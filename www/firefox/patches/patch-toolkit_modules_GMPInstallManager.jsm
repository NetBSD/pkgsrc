$NetBSD: patch-toolkit_modules_GMPInstallManager.jsm,v 1.4 2015/08/11 23:48:18 ryoon Exp $

--- toolkit/modules/GMPInstallManager.jsm.orig	2015-08-07 15:54:20.000000000 +0000
+++ toolkit/modules/GMPInstallManager.jsm
@@ -884,9 +884,7 @@ GMPDownloader.prototype = {
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
@@ -895,10 +893,12 @@ GMPDownloader.prototype = {
         // Success, set the prefs
         let now = Math.round(Date.now() / 1000);
         GMPPrefs.set(GMPPrefs.KEY_PLUGIN_LAST_UPDATE, now, gmpAddon.id);
-        // Setting the version pref signals installation completion to consumers,
-        // if you need to set other prefs etc. do it before this.
+        // Setting the path pref signals installation completion to consumers,
+        // so set the version and potential other information they use first.
         GMPPrefs.set(GMPPrefs.KEY_PLUGIN_VERSION, gmpAddon.version,
                      gmpAddon.id);
+        GMPPrefs.set(GMPPrefs.KEY_PLUGIN_PATH,
+                     installToDirPath.path, gmpAddon.id);
         // Reset the trial create pref, so that Gecko knows to do a test
         // run before reporting that the GMP works to content.
         GMPPrefs.reset(GMPPrefs.KEY_PLUGIN_TRIAL_CREATE, gmpAddon.version,
