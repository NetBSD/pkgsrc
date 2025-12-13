$NetBSD: patch-device_fido_features.cc,v 1.2 2025/12/13 14:53:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- device/fido/features.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ device/fido/features.cc
@@ -37,7 +37,7 @@ namespace device {
 // comment.
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Not yet enabled by default.
 BASE_FEATURE(kPasskeyUnlockErrorUi, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
