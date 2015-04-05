$NetBSD: patch-toolkit_modules_GMPInstallManager.jsm,v 1.2 2015/04/05 12:54:12 ryoon Exp $

--- toolkit/modules/GMPInstallManager.jsm.orig	2015-03-27 02:20:31.000000000 +0000
+++ toolkit/modules/GMPInstallManager.jsm
@@ -111,6 +111,7 @@ let GMPPrefs = {
    */
   KEY_ADDON_ENABLED: "media.{0}.enabled",
   KEY_ADDON_LAST_UPDATE: "media.{0}.lastUpdate",
+  KEY_ADDON_PATH: "media.{0}.path",
   KEY_ADDON_VERSION: "media.{0}.version",
   KEY_ADDON_AUTOUPDATE: "media.{0}.autoupdate",
   KEY_ADDON_HIDDEN: "media.{0}.hidden",
@@ -933,9 +934,7 @@ GMPDownloader.prototype = {
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
@@ -944,10 +943,12 @@ GMPDownloader.prototype = {
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
