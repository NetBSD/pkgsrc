$NetBSD: patch-src_3rdparty_chromium_media_base_media__switches.h,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/media/base/media_switches.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/media/base/media_switches.h
@@ -35,7 +35,7 @@ MEDIA_EXPORT extern const char kDisableB
 
 MEDIA_EXPORT extern const char kReportVp9AsAnUnsupportedMimeType[];
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FREEBSD) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_SOLARIS)
 MEDIA_EXPORT extern const char kAlsaInputDevice[];
 MEDIA_EXPORT extern const char kAlsaOutputDevice[];
