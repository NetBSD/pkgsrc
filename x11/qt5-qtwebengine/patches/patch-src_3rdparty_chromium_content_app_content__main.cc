$NetBSD: patch-src_3rdparty_chromium_content_app_content__main.cc,v 1.1 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/content/app/content_main.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/content/app/content_main.cc
@@ -232,7 +232,7 @@ int RunContentProcess(const ContentMainP
     base::EnableTerminationOnOutOfMemory();
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     // The various desktop environments set this environment variable that
     // allows the dbus client library to connect directly to the bus. When this
     // variable is not set (test environments like xvfb-run), the dbus client
