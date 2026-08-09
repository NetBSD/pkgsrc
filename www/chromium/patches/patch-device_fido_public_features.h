$NetBSD: patch-device_fido_public_features.h,v 1.10 2026/08/09 06:31:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- device/fido/public/features.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ device/fido/public/features.h
@@ -14,7 +14,7 @@
 namespace device {
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Allows the passkey unlock error UI to be shown.
 COMPONENT_EXPORT(FIDO_PUBLIC)
 BASE_DECLARE_FEATURE(kPasskeyUnlockErrorUi);
