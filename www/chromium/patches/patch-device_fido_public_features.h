$NetBSD: patch-device_fido_public_features.h,v 1.11 2026/09/02 13:13:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- device/fido/public/features.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ device/fido/public/features.h
@@ -14,7 +14,7 @@
 namespace device {
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Allows the passkey unlock error UI to be shown.
 COMPONENT_EXPORT(FIDO_PUBLIC)
 BASE_DECLARE_FEATURE(kPasskeyUnlockErrorUi);
