$NetBSD: patch-chrome_browser_extensions_api_runtime_chrome__runtime__api__delegate.cc,v 1.3 2025/07/07 09:23:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc
@@ -326,7 +326,11 @@ bool ChromeRuntimeAPIDelegate::GetPlatfo
   } else if (strcmp(os, "linux") == 0) {
     info->os = extensions::api::runtime::PlatformOs::kLinux;
   } else if (strcmp(os, "openbsd") == 0) {
-    info->os = extensions::api::runtime::PlatformOs::kOpenbsd;
+    info->os = extensions::api::runtime::PlatformOs::kLinux;
+  } else if (strcmp(os, "freebsd") == 0) {
+    info->os = extensions::api::runtime::PlatformOs::kLinux;
+  } else if (strcmp(os, "netbsd") == 0) {
+    info->os = extensions::api::runtime::PlatformOs::kLinux;
   } else if (strcmp(os, "android") == 0) {
     info->os = extensions::api::runtime::PlatformOs::kAndroid;
   } else {
