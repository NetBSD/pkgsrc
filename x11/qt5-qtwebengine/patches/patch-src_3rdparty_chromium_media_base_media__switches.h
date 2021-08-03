$NetBSD: patch-src_3rdparty_chromium_media_base_media__switches.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/media/base/media_switches.h.orig	2020-07-15 18:56:47.000000000 +0000
+++ src/3rdparty/chromium/media/base/media_switches.h
@@ -35,7 +35,7 @@ MEDIA_EXPORT extern const char kDisableB
 
 MEDIA_EXPORT extern const char kReportVp9AsAnUnsupportedMimeType[];
 
-#if defined(OS_LINUX) || defined(OS_FREEBSD) || defined(OS_SOLARIS)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
 MEDIA_EXPORT extern const char kAlsaInputDevice[];
 MEDIA_EXPORT extern const char kAlsaOutputDevice[];
 #endif
