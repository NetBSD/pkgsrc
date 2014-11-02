$NetBSD: patch-mozilla_toolkit_mozapps_extensions_internal_OpenH264Provider.jsm,v 1.1 2014/11/02 05:40:31 ryoon Exp $

--- mozilla/toolkit/mozapps/extensions/internal/OpenH264Provider.jsm.orig	2014-10-14 06:36:45.000000000 +0000
+++ mozilla/toolkit/mozapps/extensions/internal/OpenH264Provider.jsm
@@ -29,6 +29,7 @@ const SEC_IN_A_DAY              = 24 * 6
 const OPENH264_PLUGIN_ID       = "gmp-gmpopenh264";
 const OPENH264_PREF_BRANCH     = "media." + OPENH264_PLUGIN_ID + ".";
 const OPENH264_PREF_ENABLED    = "enabled";
+const OPENH264_PREF_PATH       = "path";
 const OPENH264_PREF_VERSION    = "version";
 const OPENH264_PREF_LASTUPDATE = "lastUpdate";
 const OPENH264_PREF_AUTOUPDATE = "autoupdate";
@@ -99,7 +100,12 @@ let OpenH264Wrapper = {
   get description() { return pluginsBundle.GetStringFromName("openH264_description"); },
   get fullDescription() { return OPENH264_FULLDESCRIPTION; },
 
-  get version() { return prefs.get(OPENH264_PREF_VERSION, ""); },
+  get version() {
+    if (this.isInstalled) {
+      return prefs.get(OPENH264_PREF_VERSION, "");
+    }
+    return "";
+  },
 
   get isActive() { return !this.userDisabled; },
   get appDisabled() { return false; },
@@ -223,24 +229,17 @@ let OpenH264Wrapper = {
 
   get pluginMimeTypes() { return []; },
   get pluginLibraries() {
-    if (this.isInstalled) {
-      let path = this.version;
-      return [path];
-    }
-    return [];
+    let path = prefs.get(OPENH264_PREF_PATH, null);
+    return path && path.length ? [OS.Path.basename(path)] : [];
   },
   get pluginFullpath() {
-    if (this.isInstalled) {
-      let path = OS.Path.join(OS.Constants.Path.profileDir,
-                              OPENH264_PLUGIN_ID,
-                              this.version);
-      return [path];
-    }
-    return [];
+    let path = prefs.get(OPENH264_PREF_PATH, null);
+    return path && path.length ? [path] : [];
   },
 
   get isInstalled() {
-    return this.version.length > 0;
+    let path = prefs.get(OPENH264_PREF_PATH, "");
+    return path.length > 0;
   },
 };
 
@@ -251,19 +250,14 @@ let OpenH264Provider = {
                                                           "OpenH264Provider" + "::");
     OpenH264Wrapper._log = Log.repository.getLoggerWithMessagePrefix("Toolkit.OpenH264Provider",
                                                                      "OpenH264Wrapper" + "::");
-    this.gmpPath = null;
-    if (OpenH264Wrapper.isInstalled) {
-      this.gmpPath = OS.Path.join(OS.Constants.Path.profileDir,
-                                  OPENH264_PLUGIN_ID,
-                                  prefs.get(OPENH264_PREF_VERSION, null));
-    }
+    this.gmpPath = prefs.get(OPENH264_PREF_PATH, null);
     let enabled = prefs.get(OPENH264_PREF_ENABLED, true);
     this._log.trace("startup() - enabled=" + enabled + ", gmpPath="+this.gmpPath);
 
 
     Services.obs.addObserver(this, AddonManager.OPTIONS_NOTIFICATION_DISPLAYED, false);
     prefs.observe(OPENH264_PREF_ENABLED, this.onPrefEnabledChanged, this);
-    prefs.observe(OPENH264_PREF_VERSION, this.onPrefVersionChanged, this);
+    prefs.observe(OPENH264_PREF_PATH, this.onPrefPathChanged, this);
     prefs.observe(OPENH264_PREF_LOGGING, configureLogging);
 
     if (this.gmpPath && enabled) {
@@ -280,7 +274,7 @@ let OpenH264Provider = {
     this._log.trace("shutdown()");
     Services.obs.removeObserver(this, AddonManager.OPTIONS_NOTIFICATION_DISPLAYED);
     prefs.ignore(OPENH264_PREF_ENABLED, this.onPrefEnabledChanged, this);
-    prefs.ignore(OPENH264_PREF_VERSION, this.onPrefVersionChanged, this);
+    prefs.ignore(OPENH264_PREF_PATH, this.onPrefPathChanged, this);
     prefs.ignore(OPENH264_PREF_LOGGING, configureLogging);
 
     return OpenH264Wrapper._updateTask;
@@ -306,25 +300,20 @@ let OpenH264Provider = {
                                            wrapper);
   },
 
-  onPrefVersionChanged: function() {
+  onPrefPathChanged: function() {
     let wrapper = OpenH264Wrapper;
 
     AddonManagerPrivate.callAddonListeners("onUninstalling", wrapper, false);
     if (this.gmpPath) {
-      this._log.info("onPrefVersionChanged() - unregistering gmp directory " + this.gmpPath);
+      this._log.info("onPrefPathChanged() - removing gmp directory " + this.gmpPath);
       gmpService.removePluginDirectory(this.gmpPath);
     }
     AddonManagerPrivate.callAddonListeners("onUninstalled", wrapper);
 
     AddonManagerPrivate.callInstallListeners("onExternalInstall", null, wrapper, null, false);
-    this.gmpPath = null;
-    if (OpenH264Wrapper.isInstalled) {
-      this.gmpPath = OS.Path.join(OS.Constants.Path.profileDir,
-                                  OPENH264_PLUGIN_ID,
-                                  prefs.get(OPENH264_PREF_VERSION, null));
-    }
+    this.gmpPath = prefs.get(OPENH264_PREF_PATH, null);
     if (this.gmpPath && wrapper.isActive) {
-      this._log.info("onPrefVersionChanged() - registering gmp directory " + this.gmpPath);
+      this._log.info("onPrefPathChanged() - adding gmp directory " + this.gmpPath);
       gmpService.addPluginDirectory(this.gmpPath);
     }
     AddonManagerPrivate.callAddonListeners("onInstalled", wrapper);
