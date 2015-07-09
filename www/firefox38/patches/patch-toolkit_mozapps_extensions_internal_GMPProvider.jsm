$NetBSD: patch-toolkit_mozapps_extensions_internal_GMPProvider.jsm,v 1.1 2015/07/09 14:13:52 ryoon Exp $

--- toolkit/mozapps/extensions/internal/GMPProvider.jsm.orig	2015-05-04 00:43:33.000000000 +0000
+++ toolkit/mozapps/extensions/internal/GMPProvider.jsm
@@ -101,12 +101,11 @@ function GMPWrapper(aPluginInfo) {
     Log.repository.getLoggerWithMessagePrefix("Toolkit.GMP",
                                               "GMPWrapper(" +
                                               this._plugin.id + ") ");
-  Preferences.observe(GMPPrefs.getPrefKey(GMPPrefs.KEY_PLUGIN_ENABLED,
-                                          this._plugin.id),
+  Preferences.observe(GMPPrefs.getPrefKey(GMPPrefs.KEY_PLUGIN_ENABLED, this._plugin.id),
                       this.onPrefEnabledChanged, this);
-  Preferences.observe(GMPPrefs.getPrefKey(GMPPrefs.KEY_PLUGIN_VERSION,
+  Preferences.observe(GMPPrefs.getPrefKey(GMPPrefs.KEY_PLUGIN_PATH,
                                           this._plugin.id),
-                      this.onPrefVersionChanged, this);
+                      this.onPrefPathChanged, this);
   if (this._plugin.isEME) {
     Preferences.observe(GMPPrefs.KEY_EME_ENABLED,
                         this.onPrefEMEGlobalEnabledChanged, this);
@@ -123,17 +122,14 @@ GMPWrapper.prototype = {
   optionsType: AddonManager.OPTIONS_TYPE_INLINE,
   get optionsURL() { return this._plugin.optionsURL; },
 
+
   set gmpPath(aPath) { this._gmpPath = aPath; },
   get gmpPath() {
-    if (!this._gmpPath && this.isInstalled) {
-      this._gmpPath = OS.Path.join(OS.Constants.Path.profileDir,
-                                   this._plugin.id,
-                                   GMPPrefs.get(GMPPrefs.KEY_PLUGIN_VERSION,
-                                                null, this._plugin.id));
+    if (!this._gmpPath) {
+      this._gmpPath = GMPPrefs.get(GMPPrefs.KEY_PLUGIN_PATH, null, this._plugin.id);
     }
     return this._gmpPath;
   },
-
   get id() { return this._plugin.id; },
   get type() { return "plugin"; },
   get isGMPlugin() { return true; },
@@ -144,8 +140,13 @@ GMPWrapper.prototype = {
   get description() { return this._plugin.description; },
   get fullDescription() { return this._plugin.fullDescription; },
 
-  get version() { return GMPPrefs.get(GMPPrefs.KEY_PLUGIN_VERSION, null,
-                                      this._plugin.id); },
+  get version() { 
+    if (this.isInstalled) {
+        return GMPPrefs.get(GMPPrefs.KEY_PLUGIN_VERSION, null,
+                                    this._plugin.id);
+    }
+    return null;
+  },
 
   get isActive() { return !this.appDisabled && !this.userDisabled; },
   get appDisabled() {
@@ -292,24 +293,17 @@ GMPWrapper.prototype = {
 
   get pluginMimeTypes() { return []; },
   get pluginLibraries() {
-    if (this.isInstalled) {
-      let path = this.version;
-      return [path];
-    }
-    return [];
+    let path = GMPPrefs.get(GMPPrefs.KEY_PLUGIN_PATH, null, this._plugin.id);
+    return path && path.length ? [OS.Path.basename(path)] : [];
   },
   get pluginFullpath() {
-    if (this.isInstalled) {
-      let path = OS.Path.join(OS.Constants.Path.profileDir,
-                              this._plugin.id,
-                              this.version);
-      return [path];
-    }
-    return [];
+    let path = GMPPrefs.get(GMPPrefs.KEY_PLUGIN_PATH, null, this._plugin.id);
+    return path && path.length ? [path] : [];
   },
 
   get isInstalled() {
-    return this.version && this.version.length > 0;
+    let path = GMPPrefs.get(GMPPrefs.KEY_PLUGIN_PATH, null, this._plugin.id);
+    return path && path.length > 0;
   },
 
   _handleEnabledChanged: function() {
@@ -389,10 +383,10 @@ GMPWrapper.prototype = {
     }
   },
 
-  onPrefVersionChanged: function() {
+  onPrefPathChanged: function() {
     AddonManagerPrivate.callAddonListeners("onUninstalling", this, false);
     if (this._gmpPath) {
-      this._log.info("onPrefVersionChanged() - unregistering gmp directory " +
+      this._log.info("onPrefPathChanged() - unregistering gmp directory " +
                      this._gmpPath);
       gmpService.removeAndDeletePluginDirectory(this._gmpPath, true /* can defer */);
     }
@@ -401,15 +395,10 @@ GMPWrapper.prototype = {
     AddonManagerPrivate.callInstallListeners("onExternalInstall", null, this,
                                              null, false);
     AddonManagerPrivate.callAddonListeners("onInstalling", this, false);
-    this._gmpPath = null;
-    if (this.isInstalled) {
-      this._gmpPath = OS.Path.join(OS.Constants.Path.profileDir,
-                                   this._plugin.id,
-                                   GMPPrefs.get(GMPPrefs.KEY_PLUGIN_VERSION,
-                                                null, this._plugin.id));
-    }
+    this._gmpPath = GMPPrefs.get(GMPPrefs.KEY_PLUGIN_PATH,
+                                 null, this._plugin.id);
     if (this._gmpPath && this.isActive) {
-      this._log.info("onPrefVersionChanged() - registering gmp directory " +
+      this._log.info("onPrefPathChanged() - registering gmp directory " +
                      this._gmpPath);
       gmpService.addPluginDirectory(this._gmpPath);
     }
@@ -431,9 +420,9 @@ GMPWrapper.prototype = {
     Preferences.ignore(GMPPrefs.getPrefKey(GMPPrefs.KEY_PLUGIN_ENABLED,
                                            this._plugin.id),
                        this.onPrefEnabledChanged, this);
-    Preferences.ignore(GMPPrefs.getPrefKey(GMPPrefs.KEY_PLUGIN_VERSION,
+    Preferences.ignore(GMPPrefs.getPrefKey(GMPPrefs.KEY_PLUGIN_PATH,
                                            this._plugin.id),
-                       this.onPrefVersionChanged, this);
+                       this.onPrefPathChanged, this);
     if (this._plugin.isEME) {
       Preferences.ignore(GMPPrefs.KEY_EME_ENABLED,
                          this.onPrefEMEGlobalEnabledChanged, this);
