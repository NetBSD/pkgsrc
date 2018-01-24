$NetBSD: patch-dom_media_flac_FlacDecoder.cpp,v 1.1 2018/01/24 16:52:08 ryoon Exp $

--- dom/media/flac/FlacDecoder.cpp.orig	2017-11-02 16:16:35.000000000 +0000
+++ dom/media/flac/FlacDecoder.cpp
@@ -7,6 +7,7 @@
 #include "FlacDecoder.h"
 #include "MediaContainerType.h"
 #include "MediaPrefs.h"
+#include "PDMFactory.h"
 
 namespace mozilla {
 
@@ -15,6 +16,10 @@ FlacDecoder::IsEnabled()
 {
 #ifdef MOZ_FFVPX
   return MediaPrefs::FlacEnabled();
+#elif defined(MOZ_FFMPEG)
+  RefPtr<PDMFactory> platform = new PDMFactory();
+  return MediaPrefs::FlacEnabled() && platform->SupportsMimeType(NS_LITERAL_CSTRING("audio/flac"),
+                                    /* DecoderDoctorDiagnostics* */ nullptr);
 #else
   // Until bug 1295886 is fixed.
   return false;
