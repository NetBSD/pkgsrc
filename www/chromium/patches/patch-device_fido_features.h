$NetBSD: patch-device_fido_features.h,v 1.2 2025/12/13 14:53:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- device/fido/features.h.orig	2025-11-19 21:40:05.000000000 +0000
+++ device/fido/features.h
@@ -13,7 +13,7 @@
 namespace device {
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Allows the passkey unlock error UI to be shown.
 COMPONENT_EXPORT(DEVICE_FIDO)
 BASE_DECLARE_FEATURE(kPasskeyUnlockErrorUi);
