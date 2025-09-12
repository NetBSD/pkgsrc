$NetBSD: patch-chrome_browser_extensions_api_runtime_chrome__runtime__api__delegate.cc,v 1.7 2025/09/12 16:02:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc
@@ -356,7 +356,11 @@ bool ChromeRuntimeAPIDelegate::GetPlatfo
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
