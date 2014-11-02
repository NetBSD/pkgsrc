$NetBSD: patch-mozilla_toolkit_modules_GMPInstallManager.jsm,v 1.1 2014/11/02 05:40:31 ryoon Exp $

--- mozilla/toolkit/modules/GMPInstallManager.jsm.orig	2014-10-14 06:36:44.000000000 +0000
+++ mozilla/toolkit/modules/GMPInstallManager.jsm
@@ -107,6 +107,7 @@ let GMPPrefs = {
    */
   KEY_LOG_ENABLED: "media.gmp-manager.log",
   KEY_ADDON_LAST_UPDATE: "media.{0}.lastUpdate",
+  KEY_ADDON_PATH: "media.{0}.path",
   KEY_ADDON_VERSION: "media.{0}.version",
   KEY_ADDON_AUTOUPDATE: "media.{0}.autoupdate",
   KEY_URL: "media.gmp-manager.url",
@@ -888,9 +889,7 @@ GMPDownloader.prototype = {
       let gmpAddon = this._gmpAddon;
       let installToDirPath = Cc["@mozilla.org/file/local;1"].
                           createInstance(Ci.nsIFile);
-      let path = OS.Path.join(OS.Constants.Path.profileDir,
-                              gmpAddon.id,
-                              gmpAddon.version);
+      let path = OS.Path.join(OS.Constants.Path.profileDir, gmpAddon.id);
       installToDirPath.initWithPath(path);
       log.info("install to directory path: " + installToDirPath.path);
       let gmpInstaller = new GMPExtractor(zipPath, installToDirPath.path);
@@ -899,10 +898,12 @@ GMPDownloader.prototype = {
         // Success, set the prefs
         let now = Math.round(Date.now() / 1000);
         GMPPrefs.set(GMPPrefs.KEY_ADDON_LAST_UPDATE, now, gmpAddon.id);
-        // Setting the version pref signals installation completion to consumers,
-        // if you need to set other prefs etc. do it before this.
+        // Setting the path pref signals installation completion to consumers,
+        // so set the version and potential other information they use first.
         GMPPrefs.set(GMPPrefs.KEY_ADDON_VERSION, gmpAddon.version,
                      gmpAddon.id);
+        GMPPrefs.set(GMPPrefs.KEY_ADDON_PATH,
+                     installToDirPath.path, gmpAddon.id);
         this._deferred.resolve(extractedPaths);
       }, err => {
         this._deferred.reject(err);
