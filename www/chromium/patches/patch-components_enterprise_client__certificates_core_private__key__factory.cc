$NetBSD: patch-components_enterprise_client__certificates_core_private__key__factory.cc,v 1.1 2026/03/14 12:40:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/enterprise/client_certificates/core/private_key_factory.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ components/enterprise/client_certificates/core/private_key_factory.cc
@@ -123,8 +123,8 @@ void PrivateKeyFactoryImpl::OnPrivateKey
     scoped_refptr<PrivateKey> private_key) {
   if (!private_key && source != PrivateKeySource::kSoftwareKey) {
     for (auto fallback_source =
-             ++std::find(std::begin(kKeySourcesOrderedBySecurity),
-                         std::end(kKeySourcesOrderedBySecurity), source);
+             (std::find(std::begin(kKeySourcesOrderedBySecurity),
+                         std::end(kKeySourcesOrderedBySecurity), source)+1);
          fallback_source != std::end(kKeySourcesOrderedBySecurity);
          fallback_source++) {
       auto it = sub_factories_.find(*fallback_source);
