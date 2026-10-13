$NetBSD: patch-device_fido_public_features.cc,v 1.15 2026/10/13 13:16:42 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- device/fido/public/features.cc.orig	2026-10-06 00:06:58.000000000 +0000
+++ device/fido/public/features.cc
@@ -34,7 +34,7 @@ namespace device {
 // comment.
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Not yet enabled by default.
 BASE_FEATURE(kPasskeyUnlockErrorUi, base::FEATURE_DISABLED_BY_DEFAULT);
 
