$NetBSD: patch-components_web__package_web__bundle__parser__factory.cc,v 1.1 2026/10/23 15:05:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/web_package/web_bundle_parser_factory.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ components/web_package/web_bundle_parser_factory.cc
@@ -72,10 +72,13 @@ void WebBundleParserFactory::GetParserFo
     mojo::PendingRemote<mojom::BundleDataSource> data_source) {
   // TODO(crbug.com/40197063): WebBundleParserFactory doesn't support
   // |base_url|. For features::kWebBundlesFromNetwork should support |base_url|.
+  // XXX crubit
+#if !BUILDFLAG(IS_BSD) 
   mojo::MakeSelfOwnedReceiver(
       std::make_unique<WebBundleParser>(std::move(data_source),
                                         base_url.value_or(GURL())),
       std::move(receiver));
+#endif
 }
 
 void WebBundleParserFactory::BindFileDataSource(
