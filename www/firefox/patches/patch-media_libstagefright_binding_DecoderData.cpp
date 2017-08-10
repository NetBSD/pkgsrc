$NetBSD: patch-media_libstagefright_binding_DecoderData.cpp,v 1.2 2017/08/10 14:46:15 ryoon Exp $

--- media/libstagefright/binding/DecoderData.cpp.orig	2017-07-31 16:20:49.000000000 +0000
+++ media/libstagefright/binding/DecoderData.cpp
@@ -13,9 +13,11 @@
 #include "mozilla/ArrayUtils.h"
 #include "include/ESDS.h"
 
+#ifdef MOZ_RUST_MP4PARSE
 // OpusDecoder header is really needed only by MP4 in rust
 #include "OpusDecoder.h"
 #include "mp4parse.h"
+#endif // MOZ_RUST_MP4PARSE
 
 using namespace stagefright;
 using mozilla::media::TimeUnit;
@@ -177,6 +179,7 @@ MP4VideoInfo::Update(const MetaData* aMe
   FindData(aMetaData, kKeyAVCC, mExtraData);
 }
 
+#ifdef MOZ_RUST_MP4PARSE
 static void
 UpdateTrackProtectedInfo(mozilla::TrackInfo& aConfig,
                          const mp4parse_sinf_info& aSinf)
@@ -263,6 +266,7 @@ MP4VideoInfo::Update(const mp4parse_trac
     mExtraData->AppendElements(video->extra_data.data, video->extra_data.length);
   }
 }
+#endif // MOZ_RUST_MP4PARSE
 
 bool
 MP4VideoInfo::IsValid() const
