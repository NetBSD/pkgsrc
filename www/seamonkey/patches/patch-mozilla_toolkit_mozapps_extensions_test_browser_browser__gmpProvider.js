$NetBSD: patch-mozilla_toolkit_mozapps_extensions_test_browser_browser__gmpProvider.js,v 1.1 2017/01/01 16:14:08 ryoon Exp $

--- mozilla/toolkit/mozapps/extensions/test/browser/browser_gmpProvider.js.orig	2016-12-14 02:09:56.000000000 +0000
+++ mozilla/toolkit/mozapps/extensions/test/browser/browser_gmpProvider.js
@@ -390,6 +390,7 @@ add_task(function* testEmeSupport() {
     } else if (addon.id == GMPScope.WIDEVINE_ID) {
       if (AppConstants.isPlatformAndVersionAtLeast("win", "6") ||
           AppConstants.platform == "macosx" ||
+          AppConstants.platform == "netbsd" ||
           AppConstants.platform == "linux") {
         Assert.ok(item, "Widevine supported, found add-on element.");
       } else {
