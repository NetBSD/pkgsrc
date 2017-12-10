$NetBSD: patch-toolkit_mozapps_extensions_test_browser_browser__gmpProvider.js,v 1.3 2017/12/10 00:45:09 ryoon Exp $

--- toolkit/mozapps/extensions/test/browser/browser_gmpProvider.js.orig	2017-09-14 20:16:02.000000000 +0000
+++ toolkit/mozapps/extensions/test/browser/browser_gmpProvider.js
@@ -371,7 +371,8 @@ add_task(async function testEmeSupport()
     } else if (addon.id == GMPScope.WIDEVINE_ID) {
       if (AppConstants.isPlatformAndVersionAtLeast("win", "6") ||
           AppConstants.platform == "macosx" ||
-          AppConstants.platform == "linux") {
+          AppConstants.platform == "linux" ||
+          AppConstants.platform == "netbsd") {
         Assert.ok(item, "Widevine supported, found add-on element.");
       } else {
         Assert.ok(!item,
