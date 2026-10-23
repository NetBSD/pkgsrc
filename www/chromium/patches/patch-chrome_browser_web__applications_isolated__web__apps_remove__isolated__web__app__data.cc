$NetBSD: patch-chrome_browser_web__applications_isolated__web__apps_remove__isolated__web__app__data.cc,v 1.1 2026/10/23 15:05:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/web_applications/isolated_web_apps/remove_isolated_web_app_data.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/web_applications/isolated_web_apps/remove_isolated_web_app_data.cc
@@ -57,6 +57,8 @@ class RemovalObserver : public content::
 void CloseBundle(Profile* profile,
                  const IwaSource& source,
                  base::OnceClosure callback) {
+// XXX crubit
+#if 0
   if (!content::AreIsolatedWebAppsEnabled(profile)) {
     // A previously installed IWA can be uninstalled even if the IWA feature
     // flag is off; in this case the reader registry will not exist.
@@ -71,6 +73,7 @@ void CloseBundle(Profile* profile,
           [&](const IwaSourceProxy& proxy) { std::move(callback).Run(); },
       },
       source.variant());
+#endif
 }
 
 }  // namespace
