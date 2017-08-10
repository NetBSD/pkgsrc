$NetBSD: patch-media_libstagefright_binding_include_mp4__demuxer_MP4Metadata.h,v 1.2 2017/08/10 14:46:15 ryoon Exp $

--- media/libstagefright/binding/include/mp4_demuxer/MP4Metadata.h.orig	2017-07-31 16:20:49.000000000 +0000
+++ media/libstagefright/binding/include/mp4_demuxer/MP4Metadata.h
@@ -13,7 +13,9 @@
 #include "MediaInfo.h"
 #include "MediaResult.h"
 #include "Stream.h"
+#ifdef MOZ_RUST_MP4PARSE
 #include "mp4parse.h"
+#endif // MOZ_RUST_MP4PARSE
 
 namespace mp4_demuxer {
 
@@ -82,6 +84,7 @@ public:
 
 private:
   UniquePtr<MP4MetadataStagefright> mStagefright;
+#ifdef MOZ_RUST_MP4PARSE
   UniquePtr<MP4MetadataRust> mRust;
   mutable bool mPreferRust;
   mutable bool mReportedAudioTrackTelemetry;
@@ -90,6 +93,7 @@ private:
   mutable bool mRustTestMode;
 #endif
   bool ShouldPreferRust() const;
+#endif // MOZ_RUST_MP4PARSE
 };
 
 } // namespace mp4_demuxer
