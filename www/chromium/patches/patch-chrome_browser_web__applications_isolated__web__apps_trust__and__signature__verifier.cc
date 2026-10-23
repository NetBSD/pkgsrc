$NetBSD: patch-chrome_browser_web__applications_isolated__web__apps_trust__and__signature__verifier.cc,v 1.1 2026/10/23 15:05:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/web_applications/isolated_web_apps/trust_and_signature_verifier.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/web_applications/isolated_web_apps/trust_and_signature_verifier.cc
@@ -32,6 +32,8 @@ void CheckTrustAndSignatures(
         void(base::expected<
              std::optional<web_package::SignedWebBundleIntegrityBlock>,
              std::string>)> callback) {
+// XXX crubit
+#if 0
   RETURN_IF_ERROR(IsolatedWebAppTrustChecker::IsOperationAllowed(
                       *profile, web_bundle_id, location.dev_mode(), operation),
                   [&](const std::string& error) {
@@ -61,6 +63,7 @@ void CheckTrustAndSignatures(
             std::move(callback).Run(base::ok(std::nullopt));
           }},
       location.variant());
+#endif
 }
 
 void CheckTrustAndSignatures(
