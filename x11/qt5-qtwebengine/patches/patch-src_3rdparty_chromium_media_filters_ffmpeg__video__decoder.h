$NetBSD: patch-src_3rdparty_chromium_media_filters_ffmpeg__video__decoder.h,v 1.1 2025/02/23 18:59:28 markd Exp $

fix for ffmpeg7 - from ArchLinux

--- src/3rdparty/chromium/media/filters/ffmpeg_video_decoder.h.orig	2023-11-09 12:02:51.000000000 +0000
+++ src/3rdparty/chromium/media/filters/ffmpeg_video_decoder.h
@@ -8,6 +8,8 @@
 #include <list>
 #include <memory>
 
+#include "base/containers/mru_cache.h"
+#include "base/util/type_safety/id_type.h"
 #include "base/callback.h"
 #include "base/macros.h"
 #include "base/memory/ref_counted.h"
@@ -85,6 +87,20 @@ class MEDIA_EXPORT FFmpegVideoDecoder : 
   // FFmpeg structures owned by this object.
   std::unique_ptr<AVCodecContext, ScopedPtrAVFreeContext> codec_context_;
 
+  // The gist here is that timestamps need to be 64 bits to store microsecond
+  // precision. A 32 bit integer would overflow at ~35 minutes at this level of
+  // precision. We can't cast the timestamp to the void ptr object used by the
+  // opaque field in ffmpeg then, because it would lose data on a 32 bit build.
+  // However, we don't actually have 2^31 timestamped frames in a single
+  // playback, so it's fine to use the 32 bit value as a key in a map which
+  // contains the actual timestamps. Additionally, we've in the past set 128
+  // outstanding frames for re-ordering as a limit for cross-thread decoding
+  // tasks, so we'll do that here too with the LRU cache.
+  using TimestampId = util::IdType<int64_t, size_t, 0>;
+
+  TimestampId::Generator timestamp_id_generator_;
+  base::MRUCache<TimestampId, int64_t> timestamp_map_;
+
   VideoDecoderConfig config_;
 
   VideoFramePool frame_pool_;
