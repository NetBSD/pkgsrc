$NetBSD: patch-chrome_browser_web__applications_isolated__web__apps_isolated__web__app__url__info.cc,v 1.1 2026/10/23 15:05:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/web_applications/isolated_web_apps/isolated_web_app_url_info.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/web_applications/isolated_web_apps/isolated_web_app_url_info.cc
@@ -64,6 +64,8 @@ void IsolatedWebAppUrlInfo::CreateFromIs
     const IwaSource& source,
     base::OnceCallback<void(base::expected<IsolatedWebAppUrlInfo, std::string>)>
         callback) {
+// XXX crubit
+#if 0
   std::visit(
       absl::Overload{
           [&](const IwaSourceBundle& bundle) {
@@ -86,6 +88,7 @@ void IsolatedWebAppUrlInfo::CreateFromIs
                 IsolatedWebAppUrlInfo::CreateFromSignedWebBundleId(bundle_id));
           }},
       source.variant());
+#endif
 }
 
 IsolatedWebAppUrlInfo::IsolatedWebAppUrlInfo(const IwaOrigin& iwa_origin)
