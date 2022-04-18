$NetBSD: patch-src_3rdparty_chromium_chrome_common_webui__url__constants.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/chrome/common/webui_url_constants.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/chrome/common/webui_url_constants.cc
@@ -341,7 +341,7 @@ bool IsSystemWebUIHost(base::StringPiece
 #endif  // defined(OS_CHROMEOS)
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 const char kChromeUIDiscardsHost[] = "discards";
 const char kChromeUIDiscardsURL[] = "chrome://discards/";
 const char kChromeUIHatsHost[] = "hats";
@@ -363,11 +363,11 @@ const char kChromeUILinuxProxyConfigHost
 #endif
 
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_ANDROID)
+    defined(OS_ANDROID) || defined(OS_BSD)
 const char kChromeUISandboxHost[] = "sandbox";
 #endif
 
-#if defined(OS_WIN) || defined(OS_MAC) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !defined(OS_CHROMEOS))
 const char kChromeUIBrowserSwitchHost[] = "browser-switch";
 const char kChromeUIBrowserSwitchURL[] = "chrome://browser-switch/";
@@ -549,14 +549,14 @@ const char* const kChromeHostURLs[] = {
     kChromeUIAssistantOptInHost,
 #endif
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
     kChromeUIDiscardsHost,
 #endif
 #if defined(OS_POSIX) && !defined(OS_MAC) && !defined(OS_ANDROID)
     kChromeUILinuxProxyConfigHost,
 #endif
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_ANDROID)
+    defined(OS_ANDROID) || defined(OS_BSD)
     kChromeUISandboxHost,
 #endif
 #if defined(OS_WIN)
