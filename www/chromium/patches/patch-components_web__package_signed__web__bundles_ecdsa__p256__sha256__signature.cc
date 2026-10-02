$NetBSD: patch-components_web__package_signed__web__bundles_ecdsa__p256__sha256__signature.cc,v 1.2 2026/10/02 11:43:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/web_package/signed_web_bundles/ecdsa_p256_sha256_signature.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ components/web_package/signed_web_bundles/ecdsa_p256_sha256_signature.cc
@@ -9,7 +9,8 @@
 #include "base/strings/stringprintf.h"
 #include "base/types/expected.h"
 #include "components/web_package/signed_web_bundles/ecdsa_p256_public_key.h"
-#include "components/web_package/signed_web_bundles/rust/signed_web_bundles_rust.h"
+#include "crypto/keypair.h"
+#include "crypto/sign.h"
 
 namespace web_package {
 
@@ -50,8 +51,9 @@ EcdsaP256SHA256Signature::EcdsaP256SHA25
 [[nodiscard]] bool EcdsaP256SHA256Signature::Verify(
     base::span<const uint8_t> message,
     const EcdsaP256PublicKey& public_key) const {
-  return signed_web_bundles::rust::verify_ecdsa_p256_signature(
-      public_key.bytes(), bytes(), message);
+  auto key = crypto::keypair::PublicKey::FromEcP256Point(public_key.bytes());
+  return crypto::sign::Verify(crypto::sign::ECDSA_SHA256, *key, message,
+                              bytes());
 }
 
 }  // namespace web_package
