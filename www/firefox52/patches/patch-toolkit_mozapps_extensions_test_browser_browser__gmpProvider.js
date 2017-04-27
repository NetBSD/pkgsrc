$NetBSD: patch-toolkit_mozapps_extensions_test_browser_browser__gmpProvider.js,v 1.1 2017/04/27 01:55:57 ryoon Exp $

* Enable Google widevine CDM for NetBSD

--- toolkit/mozapps/extensions/test/browser/browser_gmpProvider.js.orig	2016-08-10 04:19:24.000000000 +0000
+++ toolkit/mozapps/extensions/test/browser/browser_gmpProvider.js
@@ -390,6 +390,7 @@ add_task(function* testEmeSupport() {
     } else if (addon.id == GMPScope.WIDEVINE_ID) {
       if (AppConstants.isPlatformAndVersionAtLeast("win", "6") ||
           AppConstants.platform == "macosx" ||
+          AppConstants.platform == "netbsd" ||
           AppConstants.platform == "linux") {
         Assert.ok(item, "Widevine supported, found add-on element.");
       } else {
