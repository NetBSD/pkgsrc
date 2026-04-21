$NetBSD: patch-device_fido_public_features.cc,v 1.4 2026/04/21 15:21:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- device/fido/public/features.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ device/fido/public/features.cc
@@ -40,7 +40,7 @@ namespace device {
 // comment.
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enabled in M146. Remove in or after M149.
 BASE_FEATURE(kPasskeyUnlockManager, base::FEATURE_ENABLED_BY_DEFAULT);
 
