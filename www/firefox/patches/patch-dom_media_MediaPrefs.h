$NetBSD: patch-dom_media_MediaPrefs.h,v 1.1 2017/06/14 11:28:44 ryoon Exp $

--- dom/media/MediaPrefs.h.orig	2017-06-05 20:45:18.000000000 +0000
+++ dom/media/MediaPrefs.h
@@ -165,7 +165,7 @@ private:
   DECL_MEDIA_PREF("media.ogg.flac.enabled",                   FlacInOgg, bool, false);
   DECL_MEDIA_PREF("media.flac.enabled",                       FlacEnabled, bool, true);
 
-#if !defined(RELEASE_OR_BETA)
+#if defined(MOZ_RUST_MP4PARSE) && !defined(RELEASE_OR_BETA)
   DECL_MEDIA_PREF("media.rust.test_mode",                     RustTestMode, bool, false);
 #endif
 
