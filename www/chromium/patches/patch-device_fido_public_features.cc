$NetBSD: patch-device_fido_public_features.cc,v 1.6 2026/06/01 10:09:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- device/fido/public/features.cc.orig	2026-05-26 20:39:02.000000000 +0000
+++ device/fido/public/features.cc
@@ -46,7 +46,7 @@ namespace device {
 // comment.
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enabled in M146. Remove in or after M149.
 BASE_FEATURE(kPasskeyUnlockManager, base::FEATURE_ENABLED_BY_DEFAULT);
 
