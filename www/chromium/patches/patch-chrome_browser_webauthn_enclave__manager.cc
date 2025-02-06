$NetBSD: patch-chrome_browser_webauthn_enclave__manager.cc,v 1.1 2025/02/06 09:57:56 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/webauthn/enclave_manager.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/webauthn/enclave_manager.cc
@@ -693,7 +693,7 @@ base::flat_set<std::string> GetGaiaIDs(
 
 std::string UserVerifyingLabelToString(crypto::UserVerifyingKeyLabel label) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
   return label;
 #else
   return std::string("placeholder");
@@ -703,7 +703,7 @@ std::string UserVerifyingLabelToString(c
 std::optional<crypto::UserVerifyingKeyLabel> UserVerifyingKeyLabelFromString(
     std::string saved_label) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
   return saved_label;
 #else
   return std::nullopt;
