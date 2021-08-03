$NetBSD: patch-src_3rdparty_chromium_content_public_common_content__switches.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/content/public/common/content_switches.h.orig	2020-07-08 21:40:42.000000000 +0000
+++ src/3rdparty/chromium/content/public/common/content_switches.h
@@ -267,7 +267,7 @@ CONTENT_EXPORT extern const char kRemote
 CONTENT_EXPORT extern const char kRendererWaitForJavaDebugger[];
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 CONTENT_EXPORT extern const char kEnableSpeechDispatcher[];
 #endif
 
