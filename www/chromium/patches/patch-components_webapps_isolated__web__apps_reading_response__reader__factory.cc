$NetBSD: patch-components_webapps_isolated__web__apps_reading_response__reader__factory.cc,v 1.1 2026/10/23 15:05:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/webapps/isolated_web_apps/reading/response_reader_factory.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ components/webapps/isolated_web_apps/reading/response_reader_factory.cc
@@ -45,6 +45,8 @@ void IsolatedWebAppResponseReaderFactory
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
   DCHECK(!web_bundle_id.is_for_proxy_mode());
 
+  // XXX crubit
+#if 0
   auto create_reader = base::BindOnce(
       &SignedWebBundleReader::Create, web_bundle_path,
       IwaOrigin(web_bundle_id).origin().GetURL(), verify_signatures,
@@ -58,6 +60,7 @@ void IsolatedWebAppResponseReaderFactory
   } else {
     std::move(create_reader).Run();
   }
+#endif
 }
 
 void IsolatedWebAppResponseReaderFactory::OnReaderCreated(
