$NetBSD: patch-chrome_browser_webauthn_enclave__manager.cc,v 1.14 2026/01/19 16:14:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/webauthn/enclave_manager.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/webauthn/enclave_manager.cc
@@ -795,7 +795,7 @@ base::flat_set<GaiaId> GetGaiaIDs(
 
 std::string UserVerifyingLabelToString(crypto::UserVerifyingKeyLabel label) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return label;
 #else
   return std::string("placeholder");
@@ -805,7 +805,7 @@ std::string UserVerifyingLabelToString(c
 std::optional<crypto::UserVerifyingKeyLabel> UserVerifyingKeyLabelFromString(
     std::string saved_label) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return saved_label;
 #else
   return std::nullopt;
