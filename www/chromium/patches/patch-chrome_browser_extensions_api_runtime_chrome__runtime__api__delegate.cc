$NetBSD: patch-chrome_browser_extensions_api_runtime_chrome__runtime__api__delegate.cc,v 1.26 2026/09/22 13:41:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc
@@ -377,7 +377,11 @@ bool ChromeRuntimeAPIDelegate::GetPlatfo
   } else if (os == "linux") {
     info->os = extensions::api::runtime::PlatformOs::kLinux;
   } else if (os == "openbsd") {
-    info->os = extensions::api::runtime::PlatformOs::kOpenbsd;
+    info->os = extensions::api::runtime::PlatformOs::kLinux;
+  } else if (os == "freebsd") {
+    info->os = extensions::api::runtime::PlatformOs::kLinux;
+  } else if (os == "netbsd") {
+    info->os = extensions::api::runtime::PlatformOs::kLinux;
   } else if (os == "android") {
     info->os = extensions::api::runtime::PlatformOs::kAndroid;
   } else {
