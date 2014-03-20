$NetBSD: patch-content_media_gstreamer_GStreamerReader.h,v 1.1 2014/03/20 21:02:00 ryoon Exp $

--- content/media/gstreamer/GStreamerReader.h.orig	2014-03-15 05:19:11.000000000 +0000
+++ content/media/gstreamer/GStreamerReader.h
@@ -22,6 +22,7 @@
 
 #include "MediaDecoderReader.h"
 #include "MP3FrameParser.h"
+#include "ImageContainer.h"
 #include "nsRect.h"
 
 namespace mozilla {
@@ -30,10 +31,6 @@ namespace dom {
 class TimeRanges;
 }
 
-namespace layers {
-class PlanarYCbCrImage;
-}
-
 class AbstractMediaDecoder;
 
 class GStreamerReader : public MediaDecoderReader
@@ -67,10 +64,20 @@ public:
     return mInfo.HasVideo();
   }
 
+  layers::ImageContainer* GetImageContainer() { return mDecoder->GetImageContainer(); }
+
 private:
 
   void ReadAndPushData(guint aLength);
   int64_t QueryDuration();
+  nsRefPtr<layers::PlanarYCbCrImage> GetImageFromBuffer(GstBuffer* aBuffer);
+  void CopyIntoImageBuffer(GstBuffer *aBuffer, GstBuffer** aOutBuffer, nsRefPtr<layers::PlanarYCbCrImage> &image);
+  GstCaps* BuildAudioSinkCaps();
+  void InstallPadCallbacks();
+
+#if GST_VERSION_MAJOR >= 1
+  void ImageDataFromVideoFrame(GstVideoFrame *aFrame, layers::PlanarYCbCrImage::Data *aData);
+#endif
 
   /* Called once the pipeline is setup to check that the stream only contains
    * supported formats
@@ -105,20 +112,31 @@ private:
   gboolean SeekData(GstAppSrc* aSrc, guint64 aOffset);
 
   /* Called when events reach the sinks. See inline comments */
+#if GST_VERSION_MAJOR == 1
+  static GstPadProbeReturn EventProbeCb(GstPad *aPad, GstPadProbeInfo *aInfo, gpointer aUserData);
+  GstPadProbeReturn EventProbe(GstPad *aPad, GstEvent *aEvent);
+#else
   static gboolean EventProbeCb(GstPad* aPad, GstEvent* aEvent, gpointer aUserData);
   gboolean EventProbe(GstPad* aPad, GstEvent* aEvent);
+#endif
 
-  /* Called when elements in the video branch of the pipeline call
-   * gst_pad_alloc_buffer(). Used to provide PlanarYCbCrImage backed GstBuffers
-   * to the pipeline so that a memory copy can be avoided when handling YUV
-   * buffers from the pipeline to the gfx side.
-   */
+  /* Called when the video part of the pipeline allocates buffers. Used to
+   * provide PlanarYCbCrImage backed GstBuffers to the pipeline so that a memory
+   * copy can be avoided when handling YUV buffers from the pipeline to the gfx
+   * side.
+   */
+#if GST_VERSION_MAJOR == 1
+  static GstPadProbeReturn QueryProbeCb(GstPad *aPad, GstPadProbeInfo *aInfo, gpointer aUserData);
+  GstPadProbeReturn QueryProbe(GstPad *aPad, GstPadProbeInfo *aInfo, gpointer aUserData);
+#else
   static GstFlowReturn AllocateVideoBufferCb(GstPad* aPad, guint64 aOffset, guint aSize,
                                              GstCaps* aCaps, GstBuffer** aBuf);
   GstFlowReturn AllocateVideoBufferFull(GstPad* aPad, guint64 aOffset, guint aSize,
                                      GstCaps* aCaps, GstBuffer** aBuf, nsRefPtr<layers::PlanarYCbCrImage>& aImage);
   GstFlowReturn AllocateVideoBuffer(GstPad* aPad, guint64 aOffset, guint aSize,
                                      GstCaps* aCaps, GstBuffer** aBuf);
+#endif
+
 
   /* Called when the pipeline is prerolled, that is when at start or after a
    * seek, the first audio and video buffers are queued in the sinks.
@@ -167,6 +185,11 @@ private:
   bool mUseParserDuration;
   int64_t mLastParserDuration;
 
+#if GST_VERSION_MAJOR >= 1
+  GstAllocator *mAllocator;
+  GstBufferPool *mBufferPool;
+  GstVideoInfo mVideoInfo;
+#endif
   GstElement* mPlayBin;
   GstBus* mBus;
   GstAppSrc* mSource;
@@ -197,6 +220,9 @@ private:
    * DecodeAudioData and DecodeVideoFrame should not expect any more data
    */
   bool mReachedEos;
+#if GST_VERSION_MAJOR >= 1
+  bool mConfigureAlignment;
+#endif
   int fpsNum;
   int fpsDen;
 };
