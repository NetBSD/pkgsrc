$NetBSD: patch-mozilla_content_media_gstreamer_GStreamerReader.cpp,v 1.2 2014/06/22 08:54:39 ryoon Exp $

--- mozilla/content/media/gstreamer/GStreamerReader.cpp.orig	2014-06-13 00:46:04.000000000 +0000
+++ mozilla/content/media/gstreamer/GStreamerReader.cpp
@@ -10,8 +10,10 @@
 #include "AbstractMediaDecoder.h"
 #include "MediaResource.h"
 #include "GStreamerReader.h"
+#if GST_VERSION_MAJOR >= 1
+#include "GStreamerAllocator.h"
+#endif
 #include "GStreamerFormatHelper.h"
-#include "GStreamerMozVideoBuffer.h"
 #include "VideoUtils.h"
 #include "mozilla/dom/TimeRanges.h"
 #include "mozilla/Preferences.h"
@@ -33,14 +35,16 @@ extern PRLogModuleInfo* gMediaDecoderLog
 #define LOG(type, msg, ...)
 #endif
 
-extern bool
-IsYV12Format(const VideoData::YCbCrBuffer::Plane& aYPlane,
-             const VideoData::YCbCrBuffer::Plane& aCbPlane,
-             const VideoData::YCbCrBuffer::Plane& aCrPlane);
-
+#if DEBUG
 static const unsigned int MAX_CHANNELS = 4;
-// Let the demuxer work in pull mode for short files
-static const int SHORT_FILE_SIZE = 1024 * 1024;
+#endif
+// Let the demuxer work in pull mode for short files. This used to be a micro
+// optimization to have more accurate durations for ogg files in mochitests.
+// Since as of today we aren't using gstreamer to demux ogg, and having demuxers
+// work in pull mode over http makes them slower (since they really assume
+// near-zero latency in pull mode) set the constant to 0 for now, which
+// effectively disables it.
+static const int SHORT_FILE_SIZE = 0;
 // The default resource->Read() size when working in push mode
 static const int DEFAULT_SOURCE_READ_SIZE = 50 * 1024;
 
@@ -62,6 +66,10 @@ GStreamerReader::GStreamerReader(Abstrac
   : MediaDecoderReader(aDecoder),
   mMP3FrameParser(aDecoder->GetResource()->GetLength()),
   mUseParserDuration(false),
+#if GST_VERSION_MAJOR >= 1
+  mAllocator(nullptr),
+  mBufferPool(nullptr),
+#endif
   mPlayBin(nullptr),
   mBus(nullptr),
   mSource(nullptr),
@@ -74,6 +82,9 @@ GStreamerReader::GStreamerReader(Abstrac
   mAudioSinkBufferCount(0),
   mGstThreadsMonitor("media.gst.threads"),
   mReachedEos(false),
+#if GST_VERSION_MAJOR >= 1
+  mConfigureAlignment(true),
+#endif
   fpsNum(0),
   fpsDen(0)
 {
@@ -85,8 +96,12 @@ GStreamerReader::GStreamerReader(Abstrac
 
   mSinkCallbacks.eos = GStreamerReader::EosCb;
   mSinkCallbacks.new_preroll = GStreamerReader::NewPrerollCb;
+#if GST_VERSION_MAJOR >= 1
+  mSinkCallbacks.new_sample = GStreamerReader::NewBufferCb;
+#else
   mSinkCallbacks.new_buffer = GStreamerReader::NewBufferCb;
   mSinkCallbacks.new_buffer_list = nullptr;
+#endif
 
   gst_segment_init(&mVideoSegment, GST_FORMAT_UNDEFINED);
   gst_segment_init(&mAudioSegment, GST_FORMAT_UNDEFINED);
@@ -110,65 +125,59 @@ GStreamerReader::~GStreamerReader()
     mAudioAppSink = nullptr;
     gst_object_unref(mBus);
     mBus = nullptr;
+#if GST_VERSION_MAJOR >= 1
+    g_object_unref(mAllocator);
+    g_object_unref(mBufferPool);
+#endif
   }
 }
 
 nsresult GStreamerReader::Init(MediaDecoderReader* aCloneDonor)
 {
-  GError* error = nullptr;
-  if (!gst_init_check(0, 0, &error)) {
-    LOG(PR_LOG_ERROR, "gst initialization failed: %s", error->message);
-    g_error_free(error);
-    return NS_ERROR_FAILURE;
-  }
+  GStreamerFormatHelper::Instance();
+
+#if GST_VERSION_MAJOR >= 1
+  mAllocator = static_cast<GstAllocator*>(g_object_new(GST_TYPE_MOZ_GFX_MEMORY_ALLOCATOR, nullptr));
+  moz_gfx_memory_allocator_set_reader(mAllocator, this);
+
+  mBufferPool = static_cast<GstBufferPool*>(g_object_new(GST_TYPE_MOZ_GFX_BUFFER_POOL, nullptr));
+#endif
 
+#if GST_VERSION_MAJOR >= 1
+  mPlayBin = gst_element_factory_make("playbin", nullptr);
+#else
   mPlayBin = gst_element_factory_make("playbin2", nullptr);
+#endif
   if (!mPlayBin) {
-    LOG(PR_LOG_ERROR, "couldn't create playbin2");
+    LOG(PR_LOG_ERROR, "couldn't create playbin");
     return NS_ERROR_FAILURE;
   }
   g_object_set(mPlayBin, "buffer-size", 0, nullptr);
   mBus = gst_pipeline_get_bus(GST_PIPELINE(mPlayBin));
 
   mVideoSink = gst_parse_bin_from_description("capsfilter name=filter ! "
-      "appsink name=videosink sync=true max-buffers=1 "
+      "appsink name=videosink sync=false max-buffers=1 "
+#if GST_VERSION_MAJOR >= 1
+      "caps=video/x-raw,format=I420"
+#else
       "caps=video/x-raw-yuv,format=(fourcc)I420"
+#endif
       , TRUE, nullptr);
   mVideoAppSink = GST_APP_SINK(gst_bin_get_by_name(GST_BIN(mVideoSink),
         "videosink"));
-  gst_app_sink_set_callbacks(mVideoAppSink, &mSinkCallbacks,
-      (gpointer) this, nullptr);
-  GstPad* sinkpad = gst_element_get_pad(GST_ELEMENT(mVideoAppSink), "sink");
-  gst_pad_add_event_probe(sinkpad,
-      G_CALLBACK(&GStreamerReader::EventProbeCb), this);
-  gst_object_unref(sinkpad);
-  gst_pad_set_bufferalloc_function(sinkpad, GStreamerReader::AllocateVideoBufferCb);
-  gst_pad_set_element_private(sinkpad, this);
-
   mAudioSink = gst_parse_bin_from_description("capsfilter name=filter ! "
-#ifdef MOZ_SAMPLE_TYPE_FLOAT32
-        "appsink name=audiosink max-buffers=2 sync=false caps=audio/x-raw-float,"
-#ifdef IS_LITTLE_ENDIAN
-        "channels={1,2},width=32,endianness=1234", TRUE, nullptr);
-#else
-        "channels={1,2},width=32,endianness=4321", TRUE, nullptr);
-#endif
-#else
-        "appsink name=audiosink max-buffers=2 sync=false caps=audio/x-raw-int,"
-#ifdef IS_LITTLE_ENDIAN
-        "channels={1,2},width=16,endianness=1234", TRUE, nullptr);
-#else
-        "channels={1,2},width=16,endianness=4321", TRUE, nullptr);
-#endif
-#endif
+        "appsink name=audiosink sync=false max-buffers=1", TRUE, nullptr);
   mAudioAppSink = GST_APP_SINK(gst_bin_get_by_name(GST_BIN(mAudioSink),
                                                    "audiosink"));
+  GstCaps* caps = BuildAudioSinkCaps();
+  g_object_set(mAudioAppSink, "caps", caps, nullptr);
+  gst_caps_unref(caps);
+
+  gst_app_sink_set_callbacks(mVideoAppSink, &mSinkCallbacks,
+      (gpointer) this, nullptr);
   gst_app_sink_set_callbacks(mAudioAppSink, &mSinkCallbacks,
                              (gpointer) this, nullptr);
-  sinkpad = gst_element_get_pad(GST_ELEMENT(mAudioAppSink), "sink");
-  gst_pad_add_event_probe(sinkpad,
-                          G_CALLBACK(&GStreamerReader::EventProbeCb), this);
-  gst_object_unref(sinkpad);
+  InstallPadCallbacks();
 
   g_object_set(mPlayBin, "uri", "appsrc://",
                "video-sink", mVideoSink,
@@ -331,13 +340,12 @@ nsresult GStreamerReader::ReadMetadata(M
       /* Little trick: set the target caps to "skip" so that playbin2 fails to
        * find a decoder for the stream we want to skip.
        */
-      GstCaps* filterCaps = gst_caps_new_simple ("skip", nullptr);
+      GstCaps* filterCaps = gst_caps_new_simple ("skip", nullptr, nullptr);
       g_object_set(filter, "caps", filterCaps, nullptr);
       gst_caps_unref(filterCaps);
       gst_object_unref(filter);
     }
 
-    /* start the pipeline */
     LOG(PR_LOG_DEBUG, "starting metadata pipeline");
     gst_element_set_state(mPlayBin, GST_STATE_PAUSED);
 
@@ -358,6 +366,7 @@ nsresult GStreamerReader::ReadMetadata(M
       gst_message_unref(message);
       ret = NS_ERROR_FAILURE;
     } else {
+      LOG(PR_LOG_DEBUG, "read metadata pipeline prerolled");
       gst_message_unref(message);
       ret = NS_OK;
       break;
@@ -371,23 +380,8 @@ nsresult GStreamerReader::ReadMetadata(M
     /* we couldn't get this to play */
     return ret;
 
-  /* FIXME: workaround for a bug in matroskademux. This seek makes matroskademux
-   * parse the index */
-  if (gst_element_seek_simple(mPlayBin, GST_FORMAT_TIME,
-        GST_SEEK_FLAG_FLUSH, 0)) {
-    /* after a seek we need to wait again for ASYNC_DONE */
-    message = gst_bus_timed_pop_filtered(mBus, GST_CLOCK_TIME_NONE,
-       (GstMessageType)(GST_MESSAGE_ASYNC_DONE | GST_MESSAGE_ERROR));
-    if (GST_MESSAGE_TYPE(message) == GST_MESSAGE_ERROR) {
-      gst_element_set_state(mPlayBin, GST_STATE_NULL);
-      gst_message_unref(message);
-      return NS_ERROR_FAILURE;
-    }
-  }
-
   /* report the duration */
   gint64 duration;
-  GstFormat format = GST_FORMAT_TIME;
 
   if (isMP3 && mMP3FrameParser.IsMP3()) {
     // The MP3FrameParser has reported a duration; use that over the gstreamer
@@ -396,17 +390,25 @@ nsresult GStreamerReader::ReadMetadata(M
     mUseParserDuration = true;
     mLastParserDuration = mMP3FrameParser.GetDuration();
     mDecoder->SetMediaDuration(mLastParserDuration);
-
-  } else if (gst_element_query_duration(GST_ELEMENT(mPlayBin),
-      &format, &duration) && format == GST_FORMAT_TIME) {
-    // Otherwise use the gstreamer duration.
-    ReentrantMonitorAutoEnter mon(mDecoder->GetReentrantMonitor());
-    LOG(PR_LOG_DEBUG, "returning duration %" GST_TIME_FORMAT, GST_TIME_ARGS(duration));
-    duration = GST_TIME_AS_USECONDS (duration);
-    mDecoder->SetMediaDuration(duration);
-
   } else {
-    mDecoder->SetMediaSeekable(false);
+    LOG(PR_LOG_DEBUG, "querying duration");
+    // Otherwise use the gstreamer duration.
+#if GST_VERSION_MAJOR >= 1
+    if (gst_element_query_duration(GST_ELEMENT(mPlayBin),
+          GST_FORMAT_TIME, &duration)) {
+#else
+    GstFormat format = GST_FORMAT_TIME;
+    if (gst_element_query_duration(GST_ELEMENT(mPlayBin),
+      &format, &duration) && format == GST_FORMAT_TIME) {
+#endif
+      ReentrantMonitorAutoEnter mon(mDecoder->GetReentrantMonitor());
+      LOG(PR_LOG_DEBUG, "have duration %" GST_TIME_FORMAT,
+            GST_TIME_ARGS (duration));
+      duration = GST_TIME_AS_USECONDS (duration);
+      mDecoder->SetMediaDuration(duration);
+    } else {
+      mDecoder->SetMediaSeekable(false);
+    }
   }
 
   int n_video = 0, n_audio = 0;
@@ -419,7 +421,11 @@ nsresult GStreamerReader::ReadMetadata(M
   *aTags = nullptr;
 
   // Watch the pipeline for fatal errors
+#if GST_VERSION_MAJOR >= 1
+  gst_bus_set_sync_handler(mBus, GStreamerReader::ErrorCb, this, nullptr);
+#else
   gst_bus_set_sync_handler(mBus, GStreamerReader::ErrorCb, this);
+#endif
 
   /* set the pipeline to PLAYING so that it starts decoding and queueing data in
    * the appsinks */
@@ -433,19 +439,35 @@ nsresult GStreamerReader::CheckSupported
   bool done = false;
   bool unsupported = false;
 
-  GstIterator *it = gst_bin_iterate_recurse(GST_BIN(mPlayBin));
+  GstIterator* it = gst_bin_iterate_recurse(GST_BIN(mPlayBin));
   while (!done) {
+    GstIteratorResult res;
     GstElement* element;
-    GstIteratorResult res = gst_iterator_next(it, (void **)&element);
+
+#if GST_VERSION_MAJOR >= 1
+    GValue value = {0,};
+    res = gst_iterator_next(it, &value);
+#else
+    res = gst_iterator_next(it, (void **) &element);
+#endif
     switch(res) {
       case GST_ITERATOR_OK:
       {
+#if GST_VERSION_MAJOR >= 1
+        element = GST_ELEMENT (g_value_get_object (&value));
+#endif
         GstElementFactory* factory = gst_element_get_factory(element);
         if (factory) {
           const char* klass = gst_element_factory_get_klass(factory);
-          GstPad* pad = gst_element_get_pad(element, "sink");
+          GstPad* pad = gst_element_get_static_pad(element, "sink");
           if (pad) {
-            GstCaps* caps = gst_pad_get_negotiated_caps(pad);
+            GstCaps* caps;
+
+#if GST_VERSION_MAJOR >= 1
+            caps = gst_pad_get_current_caps(pad);
+#else
+            caps = gst_pad_get_negotiated_caps(pad);
+#endif
 
             if (caps) {
               /* check for demuxers but ignore elements like id3demux */
@@ -460,7 +482,11 @@ nsresult GStreamerReader::CheckSupported
           }
         }
 
+#if GST_VERSION_MAJOR >= 1
+        g_value_unset (&value);
+#else
         gst_object_unref(element);
+#endif
         done = unsupported;
         break;
       }
@@ -484,6 +510,8 @@ nsresult GStreamerReader::ResetDecode()
 {
   nsresult res = NS_OK;
 
+  LOG(PR_LOG_DEBUG, "reset decode");
+
   if (NS_FAILED(MediaDecoderReader::ResetDecode())) {
     res = NS_ERROR_FAILURE;
   }
@@ -494,6 +522,11 @@ nsresult GStreamerReader::ResetDecode()
   mVideoSinkBufferCount = 0;
   mAudioSinkBufferCount = 0;
   mReachedEos = false;
+#if GST_VERSION_MAJOR >= 1
+  mConfigureAlignment = true;
+#endif
+
+  LOG(PR_LOG_DEBUG, "reset decode done");
 
   return res;
 }
@@ -517,11 +550,11 @@ bool GStreamerReader::DecodeAudioData()
         /* We have nothing decoded so it makes no sense to return to the state machine
          * as it will call us back immediately, we'll return again and so on, wasting
          * CPU cycles for no job done. So, block here until there is either video or
-         * audio data available 
+         * audio data available
         */
         mon.Wait();
         if (!mAudioSinkBufferCount) {
-          /* There is still no audio data available, so either there is video data or 
+          /* There is still no audio data available, so either there is video data or
            * something else has happened (Eos, etc...). Return to the state machine
            * to process it.
            */
@@ -533,24 +566,44 @@ bool GStreamerReader::DecodeAudioData()
       }
     }
 
+#if GST_VERSION_MAJOR >= 1
+    GstSample *sample = gst_app_sink_pull_sample(mAudioAppSink);
+    buffer = gst_buffer_ref(gst_sample_get_buffer(sample));
+    gst_sample_unref(sample);
+#else
     buffer = gst_app_sink_pull_buffer(mAudioAppSink);
+#endif
+
     mAudioSinkBufferCount--;
   }
 
   int64_t timestamp = GST_BUFFER_TIMESTAMP(buffer);
   timestamp = gst_segment_to_stream_time(&mAudioSegment,
       GST_FORMAT_TIME, timestamp);
+
   timestamp = GST_TIME_AS_USECONDS(timestamp);
+
   int64_t duration = 0;
   if (GST_CLOCK_TIME_IS_VALID(GST_BUFFER_DURATION(buffer)))
     duration = GST_TIME_AS_USECONDS(GST_BUFFER_DURATION(buffer));
 
   int64_t offset = GST_BUFFER_OFFSET(buffer);
+#if GST_VERSION_MAJOR >= 1
+  GstMapInfo info;
+  gst_buffer_map(buffer, &info, GST_MAP_READ);
+  unsigned int size = info.size;
+#else
   unsigned int size = GST_BUFFER_SIZE(buffer);
+#endif
   int32_t frames = (size / sizeof(AudioDataValue)) / mInfo.mAudio.mChannels;
   ssize_t outSize = static_cast<size_t>(size / sizeof(AudioDataValue));
   nsAutoArrayPtr<AudioDataValue> data(new AudioDataValue[outSize]);
+#if GST_VERSION_MAJOR >= 1
+  memcpy(data, info.data, info.size);
+  gst_buffer_unmap(buffer, &info);
+#else
   memcpy(data, GST_BUFFER_DATA(buffer), GST_BUFFER_SIZE(buffer));
+#endif
   AudioData* audio = new AudioData(offset, timestamp, duration,
       frames, data.forget(), mInfo.mAudio.mChannels);
 
@@ -561,7 +614,7 @@ bool GStreamerReader::DecodeAudioData()
 }
 
 bool GStreamerReader::DecodeVideoFrame(bool &aKeyFrameSkip,
-                                         int64_t aTimeThreshold)
+                                       int64_t aTimeThreshold)
 {
   NS_ASSERTION(mDecoder->OnDecodeThread(), "Should be on decode thread.");
 
@@ -580,11 +633,11 @@ bool GStreamerReader::DecodeVideoFrame(b
         /* We have nothing decoded so it makes no sense to return to the state machine
          * as it will call us back immediately, we'll return again and so on, wasting
          * CPU cycles for no job done. So, block here until there is either video or
-         * audio data available 
+         * audio data available
         */
         mon.Wait();
         if (!mVideoSinkBufferCount) {
-          /* There is still no video data available, so either there is audio data or 
+          /* There is still no video data available, so either there is audio data or
            * something else has happened (Eos, etc...). Return to the state machine
            * to process it
            */
@@ -598,11 +651,17 @@ bool GStreamerReader::DecodeVideoFrame(b
 
     mDecoder->NotifyDecodedFrames(0, 1);
 
+#if GST_VERSION_MAJOR >= 1
+    GstSample *sample = gst_app_sink_pull_sample(mVideoAppSink);
+    buffer = gst_buffer_ref(gst_sample_get_buffer(sample));
+    gst_sample_unref(sample);
+#else
     buffer = gst_app_sink_pull_buffer(mVideoAppSink);
+#endif
     mVideoSinkBufferCount--;
   }
 
-  bool isKeyframe = !GST_BUFFER_FLAG_IS_SET(buffer, GST_BUFFER_FLAG_DISCONT);
+  bool isKeyframe = !GST_BUFFER_FLAG_IS_SET(buffer, GST_BUFFER_FLAG_DELTA_UNIT);
   if ((aKeyFrameSkip && !isKeyframe)) {
     gst_buffer_unref(buffer);
     return true;
@@ -618,10 +677,18 @@ bool GStreamerReader::DecodeVideoFrame(b
                "frame has invalid timestamp");
 
   timestamp = GST_TIME_AS_USECONDS(timestamp);
+  int64_t duration;
+  if (GST_CLOCK_TIME_IS_VALID(GST_BUFFER_DURATION(buffer)))
+    duration = GST_TIME_AS_USECONDS(GST_BUFFER_DURATION(buffer));
+  else if (fpsNum && fpsDen)
+    /* add 1-frame duration */
+    duration = gst_util_uint64_scale(GST_USECOND, fpsDen, fpsNum);
+
   if (timestamp < aTimeThreshold) {
     LOG(PR_LOG_DEBUG, "skipping frame %" GST_TIME_FORMAT
                       " threshold %" GST_TIME_FORMAT,
-                      GST_TIME_ARGS(timestamp), GST_TIME_ARGS(aTimeThreshold));
+                      GST_TIME_ARGS(timestamp * 1000),
+                      GST_TIME_ARGS(aTimeThreshold * 1000));
     gst_buffer_unref(buffer);
     return true;
   }
@@ -630,61 +697,36 @@ bool GStreamerReader::DecodeVideoFrame(b
     /* no more frames */
     return false;
 
-  int64_t duration = 0;
-  if (GST_CLOCK_TIME_IS_VALID(GST_BUFFER_DURATION(buffer)))
-    duration = GST_TIME_AS_USECONDS(GST_BUFFER_DURATION(buffer));
-  else if (fpsNum && fpsDen)
-    /* 1-frame duration */
-    duration = gst_util_uint64_scale(GST_USECOND, fpsNum, fpsDen);
-
-  nsRefPtr<PlanarYCbCrImage> image;
-  GstMozVideoBufferData* bufferdata = reinterpret_cast<GstMozVideoBufferData*>
-      GST_IS_MOZ_VIDEO_BUFFER(buffer)?gst_moz_video_buffer_get_data(GST_MOZ_VIDEO_BUFFER(buffer)):nullptr;
-
-  if(bufferdata)
-    image = bufferdata->mImage;
+#if GST_VERSION_MAJOR >= 1
+  if (mConfigureAlignment && buffer->pool) {
+    GstStructure *config = gst_buffer_pool_get_config(buffer->pool);
+    GstVideoAlignment align;
+    if (gst_buffer_pool_config_get_video_alignment(config, &align))
+      gst_video_info_align(&mVideoInfo, &align);
+    gst_structure_free(config);
+    mConfigureAlignment = false;
+  }
+#endif
 
+  nsRefPtr<PlanarYCbCrImage> image = GetImageFromBuffer(buffer);
   if (!image) {
     /* Ugh, upstream is not calling gst_pad_alloc_buffer(). Fallback to
      * allocating a PlanarYCbCrImage backed GstBuffer here and memcpy.
      */
     GstBuffer* tmp = nullptr;
-    AllocateVideoBufferFull(nullptr, GST_BUFFER_OFFSET(buffer),
-        GST_BUFFER_SIZE(buffer), nullptr, &tmp, image);
-
-    /* copy */
-    gst_buffer_copy_metadata(tmp, buffer, (GstBufferCopyFlags)GST_BUFFER_COPY_ALL);
-    memcpy(GST_BUFFER_DATA(tmp), GST_BUFFER_DATA(buffer),
-        GST_BUFFER_SIZE(tmp));
+    CopyIntoImageBuffer(buffer, &tmp, image);
     gst_buffer_unref(buffer);
     buffer = tmp;
   }
 
-  guint8* data = GST_BUFFER_DATA(buffer);
-
-  int width = mPicture.width;
-  int height = mPicture.height;
-  GstVideoFormat format = mFormat;
-
-  VideoData::YCbCrBuffer b;
-  for(int i = 0; i < 3; i++) {
-    b.mPlanes[i].mData = data + gst_video_format_get_component_offset(format, i,
-        width, height);
-    b.mPlanes[i].mStride = gst_video_format_get_row_stride(format, i, width);
-    b.mPlanes[i].mHeight = gst_video_format_get_component_height(format,
-        i, height);
-    b.mPlanes[i].mWidth = gst_video_format_get_component_width(format,
-        i, width);
-    b.mPlanes[i].mOffset = 0;
-    b.mPlanes[i].mSkip = 0;
-  }
-
-  isKeyframe = !GST_BUFFER_FLAG_IS_SET(buffer, GST_BUFFER_FLAG_DELTA_UNIT);
   int64_t offset = mDecoder->GetResource()->Tell(); // Estimate location in media.
-  VideoData* video = VideoData::Create(mInfo.mVideo, image, offset,
-                                       timestamp, duration, b,
-                                       isKeyframe, -1, mPicture);
+  VideoData* video = VideoData::CreateFromImage(mInfo.mVideo,
+                                                mDecoder->GetImageContainer(),
+                                                offset, timestamp, duration,
+                                                static_cast<Image*>(image.get()),
+                                                isKeyframe, -1, mPicture);
   mVideoQueue.Push(video);
+
   gst_buffer_unref(buffer);
 
   return true;
@@ -707,6 +749,10 @@ nsresult GStreamerReader::Seek(int64_t a
     return NS_ERROR_FAILURE;
   }
   LOG(PR_LOG_DEBUG, "seek succeeded");
+  GstMessage* message = gst_bus_timed_pop_filtered(mBus, GST_CLOCK_TIME_NONE,
+               (GstMessageType)(GST_MESSAGE_ASYNC_DONE | GST_MESSAGE_ERROR));
+  gst_message_unref(message);
+  LOG(PR_LOG_DEBUG, "seek completed");
 
   return DecodeToTarget(aTarget);
 }
@@ -718,7 +764,9 @@ nsresult GStreamerReader::GetBuffered(do
     return NS_OK;
   }
 
+#if GST_VERSION_MAJOR == 0
   GstFormat format = GST_FORMAT_TIME;
+#endif
   MediaResource* resource = mDecoder->GetResource();
   nsTArray<MediaByteRange> ranges;
   resource->GetCachedRanges(ranges);
@@ -740,12 +788,21 @@ nsresult GStreamerReader::GetBuffered(do
     int64_t endOffset = ranges[index].mEnd;
     gint64 startTime, endTime;
 
+#if GST_VERSION_MAJOR >= 1
+    if (!gst_element_query_convert(GST_ELEMENT(mPlayBin), GST_FORMAT_BYTES,
+      startOffset, GST_FORMAT_TIME, &startTime))
+      continue;
+    if (!gst_element_query_convert(GST_ELEMENT(mPlayBin), GST_FORMAT_BYTES,
+      endOffset, GST_FORMAT_TIME, &endTime))
+      continue;
+#else
     if (!gst_element_query_convert(GST_ELEMENT(mPlayBin), GST_FORMAT_BYTES,
       startOffset, &format, &startTime) || format != GST_FORMAT_TIME)
       continue;
     if (!gst_element_query_convert(GST_ELEMENT(mPlayBin), GST_FORMAT_BYTES,
       endOffset, &format, &endTime) || format != GST_FORMAT_TIME)
       continue;
+#endif
 
     double start = (double) GST_TIME_AS_USECONDS (startTime) / GST_MSECOND;
     double end = (double) GST_TIME_AS_USECONDS (endTime) / GST_MSECOND;
@@ -766,7 +823,13 @@ void GStreamerReader::ReadAndPushData(gu
   nsresult rv = NS_OK;
 
   GstBuffer* buffer = gst_buffer_new_and_alloc(aLength);
+#if GST_VERSION_MAJOR >= 1
+  GstMapInfo info;
+  gst_buffer_map(buffer, &info, GST_MAP_WRITE);
+  guint8 *data = info.data;
+#else
   guint8* data = GST_BUFFER_DATA(buffer);
+#endif
   uint32_t size = 0, bytesRead = 0;
   while(bytesRead < aLength) {
     rv = resource->Read(reinterpret_cast<char*>(data + bytesRead),
@@ -780,7 +843,12 @@ void GStreamerReader::ReadAndPushData(gu
   int64_t offset2 = resource->Tell();
   unused << offset2;
 
+#if GST_VERSION_MAJOR >= 1
+  gst_buffer_unmap(buffer, &info);
+  gst_buffer_set_size(buffer, bytesRead);
+#else
   GST_BUFFER_SIZE(buffer) = bytesRead;
+#endif
 
   GstFlowReturn ret = gst_app_src_push_buffer(mSource, gst_buffer_ref(buffer));
   if (ret != GST_FLOW_OK) {
@@ -813,8 +881,13 @@ int64_t GStreamerReader::QueryDuration()
   gint64 duration = 0;
   GstFormat format = GST_FORMAT_TIME;
 
+#if GST_VERSION_MAJOR >= 1
+  if (gst_element_query_duration(GST_ELEMENT(mPlayBin),
+      format, &duration)) {
+#else
   if (gst_element_query_duration(GST_ELEMENT(mPlayBin),
       &format, &duration)) {
+#endif
     if (format == GST_FORMAT_TIME) {
       LOG(PR_LOG_DEBUG, "pipeline duration %" GST_TIME_FORMAT,
             GST_TIME_ARGS (duration));
@@ -893,109 +966,6 @@ gboolean GStreamerReader::SeekData(GstAp
   return NS_SUCCEEDED(rv);
 }
 
-gboolean GStreamerReader::EventProbeCb(GstPad* aPad,
-                                         GstEvent* aEvent,
-                                         gpointer aUserData)
-{
-  GStreamerReader* reader = reinterpret_cast<GStreamerReader*>(aUserData);
-  return reader->EventProbe(aPad, aEvent);
-}
-
-gboolean GStreamerReader::EventProbe(GstPad* aPad, GstEvent* aEvent)
-{
-  GstElement* parent = GST_ELEMENT(gst_pad_get_parent(aPad));
-  switch(GST_EVENT_TYPE(aEvent)) {
-    case GST_EVENT_NEWSEGMENT:
-    {
-      gboolean update;
-      gdouble rate;
-      GstFormat format;
-      gint64 start, stop, position;
-      GstSegment* segment;
-
-      /* Store the segments so we can convert timestamps to stream time, which
-       * is what the upper layers sync on.
-       */
-      ReentrantMonitorAutoEnter mon(mGstThreadsMonitor);
-      gst_event_parse_new_segment(aEvent, &update, &rate, &format,
-          &start, &stop, &position);
-      if (parent == GST_ELEMENT(mVideoAppSink))
-        segment = &mVideoSegment;
-      else
-        segment = &mAudioSegment;
-      gst_segment_set_newsegment(segment, update, rate, format,
-          start, stop, position);
-      break;
-    }
-    case GST_EVENT_FLUSH_STOP:
-      /* Reset on seeks */
-      ResetDecode();
-      break;
-    default:
-      break;
-  }
-  gst_object_unref(parent);
-
-  return TRUE;
-}
-
-GstFlowReturn GStreamerReader::AllocateVideoBufferFull(GstPad* aPad,
-                                                       guint64 aOffset,
-                                                       guint aSize,
-                                                       GstCaps* aCaps,
-                                                       GstBuffer** aBuf,
-                                                       nsRefPtr<PlanarYCbCrImage>& aImage)
-{
-  /* allocate an image using the container */
-  ImageContainer* container = mDecoder->GetImageContainer();
-  if (!container) {
-    // We don't have an ImageContainer. We probably belong to an <audio>
-    // element.
-    return GST_FLOW_NOT_SUPPORTED;
-  }
-  PlanarYCbCrImage* img =
-    reinterpret_cast<PlanarYCbCrImage*>(
-      container->CreateImage(ImageFormat::PLANAR_YCBCR).get());
-  nsRefPtr<PlanarYCbCrImage> image = dont_AddRef(img);
-
-  /* prepare a GstBuffer pointing to the underlying PlanarYCbCrImage buffer */
-  GstBuffer* buf = GST_BUFFER(gst_moz_video_buffer_new());
-  GST_BUFFER_SIZE(buf) = aSize;
-  /* allocate the actual YUV buffer */
-  GST_BUFFER_DATA(buf) = image->AllocateAndGetNewBuffer(aSize);
-
-  aImage = image;
-
-  /* create a GstMozVideoBufferData to hold the image */
-  GstMozVideoBufferData* bufferdata = new GstMozVideoBufferData(image);
-
-  /* Attach bufferdata to our GstMozVideoBuffer, it will take care to free it */
-  gst_moz_video_buffer_set_data(GST_MOZ_VIDEO_BUFFER(buf), bufferdata);
-
-  *aBuf = buf;
-  return GST_FLOW_OK;
-}
-
-GstFlowReturn GStreamerReader::AllocateVideoBufferCb(GstPad* aPad,
-                                                     guint64 aOffset,
-                                                     guint aSize,
-                                                     GstCaps* aCaps,
-                                                     GstBuffer** aBuf)
-{
-  GStreamerReader* reader = reinterpret_cast<GStreamerReader*>(gst_pad_get_element_private(aPad));
-  return reader->AllocateVideoBuffer(aPad, aOffset, aSize, aCaps, aBuf);
-}
-
-GstFlowReturn GStreamerReader::AllocateVideoBuffer(GstPad* aPad,
-                                                   guint64 aOffset,
-                                                   guint aSize,
-                                                   GstCaps* aCaps,
-                                                   GstBuffer** aBuf)
-{
-  nsRefPtr<PlanarYCbCrImage> image;
-  return AllocateVideoBufferFull(aPad, aOffset, aSize, aCaps, aBuf, image);
-}
-
 GstFlowReturn GStreamerReader::NewPrerollCb(GstAppSink* aSink,
                                               gpointer aUserData)
 {
@@ -1012,8 +982,12 @@ void GStreamerReader::AudioPreroll()
 {
   /* The first audio buffer has reached the audio sink. Get rate and channels */
   LOG(PR_LOG_DEBUG, "Audio preroll");
-  GstPad* sinkpad = gst_element_get_pad(GST_ELEMENT(mAudioAppSink), "sink");
+  GstPad* sinkpad = gst_element_get_static_pad(GST_ELEMENT(mAudioAppSink), "sink");
+#if GST_VERSION_MAJOR >= 1
+  GstCaps *caps = gst_pad_get_current_caps(sinkpad);
+#else
   GstCaps* caps = gst_pad_get_negotiated_caps(sinkpad);
+#endif
   GstStructure* s = gst_caps_get_structure(caps, 0);
   mInfo.mAudio.mRate = mInfo.mAudio.mChannels = 0;
   gst_structure_get_int(s, "rate", (gint*) &mInfo.mAudio.mRate);
@@ -1031,9 +1005,18 @@ void GStreamerReader::VideoPreroll()
 {
   /* The first video buffer has reached the video sink. Get width and height */
   LOG(PR_LOG_DEBUG, "Video preroll");
-  GstPad* sinkpad = gst_element_get_pad(GST_ELEMENT(mVideoAppSink), "sink");
+  GstPad* sinkpad = gst_element_get_static_pad(GST_ELEMENT(mVideoAppSink), "sink");
+#if GST_VERSION_MAJOR >= 1
+  GstCaps* caps = gst_pad_get_current_caps(sinkpad);
+  memset (&mVideoInfo, 0, sizeof (mVideoInfo));
+  gst_video_info_from_caps(&mVideoInfo, caps);
+  mFormat = mVideoInfo.finfo->format;
+  mPicture.width = mVideoInfo.width;
+  mPicture.height = mVideoInfo.height;
+#else
   GstCaps* caps = gst_pad_get_negotiated_caps(sinkpad);
   gst_video_format_parse_caps(caps, &mFormat, &mPicture.width, &mPicture.height);
+#endif
   GstStructure* structure = gst_caps_get_structure(caps, 0);
   gst_structure_get_fraction(structure, "framerate", &fpsNum, &fpsDen);
   NS_ASSERTION(mPicture.width && mPicture.height, "invalid video resolution");
@@ -1062,6 +1045,7 @@ void GStreamerReader::NewVideoBuffer()
   /* We have a new video buffer queued in the video sink. Increment the counter
    * and notify the decode thread potentially blocked in DecodeVideoFrame
    */
+
   mDecoder->NotifyDecodedFrames(1, 0);
   mVideoSinkBufferCount++;
   mon.NotifyAll();
@@ -1198,5 +1182,199 @@ void GStreamerReader::NotifyDataArrived(
   }
 }
 
+#if GST_VERSION_MAJOR >= 1
+GstCaps* GStreamerReader::BuildAudioSinkCaps()
+{
+  GstCaps* caps = gst_caps_from_string("audio/x-raw, channels={1,2}");
+  const char* format;
+#ifdef MOZ_SAMPLE_TYPE_FLOAT32
+#ifdef IS_LITTLE_ENDIAN
+  format = "F32LE";
+#else
+  format = "F32BE";
+#endif
+#else /* !MOZ_SAMPLE_TYPE_FLOAT32 */
+#ifdef IS_LITTLE_ENDIAN
+  format = "S16LE";
+#else
+  format = "S16BE";
+#endif
+#endif
+  gst_caps_set_simple(caps, "format", G_TYPE_STRING, format, nullptr);
+
+  return caps;
+}
+
+void GStreamerReader::InstallPadCallbacks()
+{
+  GstPad* sinkpad = gst_element_get_static_pad(GST_ELEMENT(mVideoAppSink), "sink");
+
+  gst_pad_add_probe(sinkpad,
+      (GstPadProbeType) (GST_PAD_PROBE_TYPE_SCHEDULING |
+        GST_PAD_PROBE_TYPE_EVENT_DOWNSTREAM |
+        GST_PAD_PROBE_TYPE_EVENT_UPSTREAM |
+        GST_PAD_PROBE_TYPE_EVENT_FLUSH),
+      &GStreamerReader::EventProbeCb, this, nullptr);
+  gst_pad_add_probe(sinkpad, GST_PAD_PROBE_TYPE_QUERY_DOWNSTREAM,
+      GStreamerReader::QueryProbeCb, nullptr, nullptr);
+
+  gst_pad_set_element_private(sinkpad, this);
+  gst_object_unref(sinkpad);
+
+  sinkpad = gst_element_get_static_pad(GST_ELEMENT(mAudioAppSink), "sink");
+  gst_pad_add_probe(sinkpad,
+      (GstPadProbeType) (GST_PAD_PROBE_TYPE_SCHEDULING |
+        GST_PAD_PROBE_TYPE_EVENT_DOWNSTREAM |
+        GST_PAD_PROBE_TYPE_EVENT_UPSTREAM |
+        GST_PAD_PROBE_TYPE_EVENT_FLUSH),
+      &GStreamerReader::EventProbeCb, this, nullptr);
+  gst_object_unref(sinkpad);
+}
+
+GstPadProbeReturn GStreamerReader::EventProbeCb(GstPad *aPad,
+                                                GstPadProbeInfo *aInfo,
+                                                gpointer aUserData)
+{
+  GStreamerReader *reader = (GStreamerReader *) aUserData;
+  GstEvent *aEvent = (GstEvent *)aInfo->data;
+  return reader->EventProbe(aPad, aEvent);
+}
+
+GstPadProbeReturn GStreamerReader::EventProbe(GstPad *aPad, GstEvent *aEvent)
+{
+  GstElement* parent = GST_ELEMENT(gst_pad_get_parent(aPad));
+
+  LOG(PR_LOG_DEBUG, "event probe %s", GST_EVENT_TYPE_NAME (aEvent));
+
+  switch(GST_EVENT_TYPE(aEvent)) {
+    case GST_EVENT_SEGMENT:
+    {
+      const GstSegment *newSegment;
+      GstSegment* segment;
+
+      /* Store the segments so we can convert timestamps to stream time, which
+       * is what the upper layers sync on.
+       */
+      ReentrantMonitorAutoEnter mon(mGstThreadsMonitor);
+#if GST_VERSION_MINOR <= 1 && GST_VERSION_MICRO < 1
+      ResetDecode();
+#endif
+      gst_event_parse_segment(aEvent, &newSegment);
+      if (parent == GST_ELEMENT(mVideoAppSink))
+        segment = &mVideoSegment;
+      else
+        segment = &mAudioSegment;
+      gst_segment_copy_into (newSegment, segment);
+      break;
+    }
+    case GST_EVENT_FLUSH_STOP:
+      /* Reset on seeks */
+      ResetDecode();
+      break;
+    default:
+      break;
+  }
+  gst_object_unref(parent);
+
+  return GST_PAD_PROBE_OK;
+}
+
+GstPadProbeReturn GStreamerReader::QueryProbeCb(GstPad* aPad, GstPadProbeInfo* aInfo, gpointer aUserData)
+{
+  GStreamerReader* reader = reinterpret_cast<GStreamerReader*>(gst_pad_get_element_private(aPad));
+  return reader->QueryProbe(aPad, aInfo, aUserData);
+}
+
+GstPadProbeReturn GStreamerReader::QueryProbe(GstPad* aPad, GstPadProbeInfo* aInfo, gpointer aUserData)
+{
+  GstQuery *query = gst_pad_probe_info_get_query(aInfo);
+  GstPadProbeReturn ret = GST_PAD_PROBE_OK;
+
+  switch (GST_QUERY_TYPE (query)) {
+    case GST_QUERY_ALLOCATION:
+      GstCaps *caps;
+      GstVideoInfo info;
+      gboolean need_pool;
+
+      gst_query_parse_allocation(query, &caps, &need_pool);
+      gst_video_info_init(&info);
+      gst_video_info_from_caps(&info, caps);
+      gst_query_add_allocation_param(query, mAllocator, nullptr);
+      gst_query_add_allocation_pool(query, mBufferPool, info.size, 0, 0);
+      gst_query_add_allocation_meta(query, GST_VIDEO_META_API_TYPE, nullptr);
+      break;
+    default:
+      break;
+  }
+
+  return ret;
+}
+
+void GStreamerReader::ImageDataFromVideoFrame(GstVideoFrame *aFrame,
+                                              PlanarYCbCrImage::Data *aData)
+{
+  NS_ASSERTION(GST_VIDEO_INFO_IS_YUV(&mVideoInfo),
+               "Non-YUV video frame formats not supported");
+  NS_ASSERTION(GST_VIDEO_FRAME_N_COMPONENTS(aFrame) == 3,
+               "Unsupported number of components in video frame");
+
+  aData->mPicX = aData->mPicY = 0;
+  aData->mPicSize = gfx::IntSize(mPicture.width, mPicture.height);
+  aData->mStereoMode = StereoMode::MONO;
+
+  aData->mYChannel = GST_VIDEO_FRAME_COMP_DATA(aFrame, 0);
+  aData->mYStride = GST_VIDEO_FRAME_COMP_STRIDE(aFrame, 0);
+  aData->mYSize = gfx::IntSize(GST_VIDEO_FRAME_COMP_WIDTH(aFrame, 0),
+                          GST_VIDEO_FRAME_COMP_HEIGHT(aFrame, 0));
+  aData->mYSkip = GST_VIDEO_FRAME_COMP_PSTRIDE(aFrame, 0) - 1;
+  aData->mCbCrStride = GST_VIDEO_FRAME_COMP_STRIDE(aFrame, 1);
+  aData->mCbCrSize = gfx::IntSize(GST_VIDEO_FRAME_COMP_WIDTH(aFrame, 1),
+                             GST_VIDEO_FRAME_COMP_HEIGHT(aFrame, 1));
+  aData->mCbChannel = GST_VIDEO_FRAME_COMP_DATA(aFrame, 1);
+  aData->mCrChannel = GST_VIDEO_FRAME_COMP_DATA(aFrame, 2);
+  aData->mCbSkip = GST_VIDEO_FRAME_COMP_PSTRIDE(aFrame, 1) - 1;
+  aData->mCrSkip = GST_VIDEO_FRAME_COMP_PSTRIDE(aFrame, 2) - 1;
+}
+
+nsRefPtr<PlanarYCbCrImage> GStreamerReader::GetImageFromBuffer(GstBuffer* aBuffer)
+{
+  nsRefPtr<PlanarYCbCrImage> image = nullptr;
+
+  if (gst_buffer_n_memory(aBuffer) == 1) {
+    GstMemory* mem = gst_buffer_peek_memory(aBuffer, 0);
+    if (GST_IS_MOZ_GFX_MEMORY_ALLOCATOR(mem->allocator)) {
+      image = moz_gfx_memory_get_image(mem);
+
+      GstVideoFrame frame;
+      gst_video_frame_map(&frame, &mVideoInfo, aBuffer, GST_MAP_READ);
+      PlanarYCbCrImage::Data data;
+      ImageDataFromVideoFrame(&frame, &data);
+      image->SetDataNoCopy(data);
+      gst_video_frame_unmap(&frame);
+    }
+  }
+
+  return image;
+}
+
+void GStreamerReader::CopyIntoImageBuffer(GstBuffer* aBuffer,
+                                          GstBuffer** aOutBuffer,
+                                          nsRefPtr<PlanarYCbCrImage> &image)
+{
+  *aOutBuffer = gst_buffer_new_allocate(mAllocator, gst_buffer_get_size(aBuffer), nullptr);
+  GstMemory *mem = gst_buffer_peek_memory(*aOutBuffer, 0);
+  GstMapInfo map_info;
+  gst_memory_map(mem, &map_info, GST_MAP_WRITE);
+  gst_buffer_extract(aBuffer, 0, map_info.data, gst_buffer_get_size(aBuffer));
+  gst_memory_unmap(mem, &map_info);
+
+  /* create a new gst buffer with the newly created memory and copy the
+   * metadata over from the incoming buffer */
+  gst_buffer_copy_into(*aOutBuffer, aBuffer,
+      (GstBufferCopyFlags)(GST_BUFFER_COPY_METADATA), 0, -1);
+  image = GetImageFromBuffer(*aOutBuffer);
+}
+#endif
+
 } // namespace mozilla
 
