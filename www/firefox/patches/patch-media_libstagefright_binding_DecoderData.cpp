$NetBSD: patch-media_libstagefright_binding_DecoderData.cpp,v 1.1 2017/06/14 11:28:44 ryoon Exp $

--- media/libstagefright/binding/DecoderData.cpp.orig	2017-06-05 20:45:14.000000000 +0000
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
 
@@ -187,6 +189,7 @@ MP4VideoInfo::Update(const MetaData* aMe
 
 }
 
+#ifdef MOZ_RUST_MP4PARSE
 static void
 UpdateTrackProtectedInfo(mozilla::TrackInfo& aConfig,
                          const mp4parse_sinf_info& aSinf)
@@ -266,6 +269,7 @@ MP4VideoInfo::Update(const mp4parse_trac
     mExtraData->AppendElements(video->extra_data.data, video->extra_data.length);
   }
 }
+#endif // MOZ_RUST_MP4PARSE
 
 bool
 MP4VideoInfo::IsValid() const
