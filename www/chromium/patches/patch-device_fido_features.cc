$NetBSD: patch-device_fido_features.cc,v 1.4 2026/01/19 16:14:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- device/fido/features.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ device/fido/features.cc
@@ -37,7 +37,7 @@ namespace device {
 // comment.
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Not yet enabled by default.
 BASE_FEATURE(kPasskeyUnlockManager, base::FEATURE_DISABLED_BY_DEFAULT);
 
