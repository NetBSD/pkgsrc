$NetBSD: patch-chrome_browser_webauthn_unexportable__key__utils.cc,v 1.32 2026/11/08 15:38:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/webauthn/unexportable_key_utils.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ chrome/browser/webauthn/unexportable_key_utils.cc
@@ -79,7 +79,7 @@ GetWebAuthnUnexportableKeyProvider() {
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // On Linux, access to the TPM is complex compared to Windows and macOS.
   // There are libraries that _should_ work with a TPM 2.0, but Linux
   // often runs on non-PCs, where TPMs will probably never exist. Thus
