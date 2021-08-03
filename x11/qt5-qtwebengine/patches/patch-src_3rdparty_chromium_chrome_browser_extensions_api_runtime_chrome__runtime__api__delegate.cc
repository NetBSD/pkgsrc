$NetBSD: patch-src_3rdparty_chromium_chrome_browser_extensions_api_runtime_chrome__runtime__api__delegate.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc.orig	2020-07-08 21:40:34.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc
@@ -294,6 +294,8 @@ bool ChromeRuntimeAPIDelegate::GetPlatfo
     info->os = extensions::api::runtime::PLATFORM_OS_LINUX;
   } else if (strcmp(os, "openbsd") == 0) {
     info->os = extensions::api::runtime::PLATFORM_OS_OPENBSD;
+  } else if (strcmp(os, "netbsd") == 0) {
+    info->os = extensions::api::runtime::PLATFORM_OS_NETBSD;
   } else {
     NOTREACHED();
     return false;
