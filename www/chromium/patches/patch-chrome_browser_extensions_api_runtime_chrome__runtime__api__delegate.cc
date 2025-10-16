$NetBSD: patch-chrome_browser_extensions_api_runtime_chrome__runtime__api__delegate.cc,v 1.8 2025/10/16 19:43:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc
@@ -353,7 +353,11 @@ bool ChromeRuntimeAPIDelegate::GetPlatfo
   } else if (UNSAFE_TODO(strcmp(os, "linux")) == 0) {
     info->os = extensions::api::runtime::PlatformOs::kLinux;
   } else if (UNSAFE_TODO(strcmp(os, "openbsd")) == 0) {
-    info->os = extensions::api::runtime::PlatformOs::kOpenbsd;
+    info->os = extensions::api::runtime::PlatformOs::kLinux;
+  } else if (UNSAFE_TODO(strcmp(os, "freebsd")) == 0) {
+    info->os = extensions::api::runtime::PlatformOs::kLinux;
+  } else if (UNSAFE_TODO(strcmp(os, "netbsd")) == 0) {
+    info->os = extensions::api::runtime::PlatformOs::kLinux;
   } else if (UNSAFE_TODO(strcmp(os, "android")) == 0) {
     info->os = extensions::api::runtime::PlatformOs::kAndroid;
   } else {
