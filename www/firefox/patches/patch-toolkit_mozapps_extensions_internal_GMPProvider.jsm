$NetBSD: patch-toolkit_mozapps_extensions_internal_GMPProvider.jsm,v 1.1 2015/04/05 12:54:12 ryoon Exp $

--- toolkit/mozapps/extensions/internal/GMPProvider.jsm.orig	2015-03-27 02:20:31.000000000 +0000
+++ toolkit/mozapps/extensions/internal/GMPProvider.jsm
@@ -40,6 +40,7 @@ const KEY_LOGGING_LEVEL      = KEY_LOG_B
 const KEY_LOGGING_DUMP       = KEY_LOG_BASE + "dump";
 const KEY_EME_ENABLED        = "media.eme.enabled"; // Global pref to enable/disable all EME plugins
 const KEY_PLUGIN_ENABLED     = "media.{0}.enabled";
+const KEY_PLUGIN_PATH        = "media.{0}.path";
 const KEY_PLUGIN_LAST_UPDATE = "media.{0}.lastUpdate";
 const KEY_PLUGIN_VERSION     = "media.{0}.version";
 const KEY_PLUGIN_AUTOUPDATE  = "media.{0}.autoupdate";
@@ -165,8 +166,8 @@ function GMPWrapper(aPluginInfo) {
                                               this._plugin.id + ") ");
   Preferences.observe(GMPPrefs.getPrefKey(KEY_PLUGIN_ENABLED, this._plugin.id),
                       this.onPrefEnabledChanged, this);
-  Preferences.observe(GMPPrefs.getPrefKey(KEY_PLUGIN_VERSION, this._plugin.id),
-                      this.onPrefVersionChanged, this);
+  Preferences.observe(GMPPrefs.getPrefKey(KEY_PLUGIN_PATH, this._plugin.id),
+                      this.onPrefPathChanged, this);
   if (this._plugin.isEME) {
     Preferences.observe(GMPPrefs.getPrefKey(KEY_EME_ENABLED, this._plugin.id),
                         this.onPrefEnabledChanged, this);
@@ -183,11 +184,8 @@ GMPWrapper.prototype = {
 
   set gmpPath(aPath) { this._gmpPath = aPath; },
   get gmpPath() {
-    if (!this._gmpPath && this.isInstalled) {
-      this._gmpPath = OS.Path.join(OS.Constants.Path.profileDir,
-                                   this._plugin.id,
-                                   GMPPrefs.get(KEY_PLUGIN_VERSION, null,
-                                                this._plugin.id));
+    if (!this._gmpPath) {
+      this._gmpPath = GMPPrefs.get(KEY_PLUGIN_PATH, null, this._plugin.id);
     }
     return this._gmpPath;
   },
@@ -202,8 +200,13 @@ GMPWrapper.prototype = {
   get description() { return this._plugin.description; },
   get fullDescription() { return this._plugin.fullDescription; },
 
-  get version() { return GMPPrefs.get(KEY_PLUGIN_VERSION, null,
-                                      this._plugin.id); },
+  get version() { 
+    if (this.isInstalled) {
+        return GMPPrefs.get(KEY_PLUGIN_VERSION, null,
+                                    this._plugin.id);
+    }
+    return null;
+  },
 
   get isActive() { return !this.userDisabled; },
   get appDisabled() { return false; },
@@ -346,24 +349,17 @@ GMPWrapper.prototype = {
 
   get pluginMimeTypes() { return []; },
   get pluginLibraries() {
-    if (this.isInstalled) {
-      let path = this.version;
-      return [path];
-    }
-    return [];
+    let path = GMPPrefs.get(KEY_PLUGIN_PATH, null, this._plugin.id);
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
+    let path = GMPPrefs.get(KEY_PLUGIN_PATH, null, this._plugin.id);
+    return path && path.length ? [path] : [];
   },
 
   get isInstalled() {
-    return this.version && this.version.length > 0;
+    let path = GMPPrefs.get(KEY_PLUGIN_PATH, null, this._plugin.id);
+    return path && path.length > 0;
   },
 
   onPrefEnabledChanged: function() {
@@ -386,10 +382,10 @@ GMPWrapper.prototype = {
                                            this);
   },
 
-  onPrefVersionChanged: function() {
+  onPrefPathChanged: function() {
     AddonManagerPrivate.callAddonListeners("onUninstalling", this, false);
     if (this._gmpPath) {
-      this._log.info("onPrefVersionChanged() - unregistering gmp directory " +
+      this._log.info("onPrefPathChanged() - unregistering gmp directory " +
                      this._gmpPath);
       gmpService.removePluginDirectory(this._gmpPath);
     }
@@ -397,15 +393,9 @@ GMPWrapper.prototype = {
 
     AddonManagerPrivate.callInstallListeners("onExternalInstall", null, this,
                                              null, false);
-    this._gmpPath = null;
-    if (this.isInstalled) {
-      this._gmpPath = OS.Path.join(OS.Constants.Path.profileDir,
-                                   this._plugin.id,
-                                   GMPPrefs.get(KEY_PLUGIN_VERSION, null,
-                                                this._plugin.id));
-    }
+    this._gmpPath = GMPPrefs.get(KEY_PLUGIN_PATH, null, this._plugin.id);
     if (this._gmpPath && this.isActive) {
-      this._log.info("onPrefVersionChanged() - registering gmp directory " +
+      this._log.info("onPrefPathChanged() - registering gmp directory " +
                      this._gmpPath);
       gmpService.addPluginDirectory(this._gmpPath);
     }
@@ -415,8 +405,8 @@ GMPWrapper.prototype = {
   shutdown: function() {
     Preferences.ignore(GMPPrefs.getPrefKey(KEY_PLUGIN_ENABLED, this._plugin.id),
                        this.onPrefEnabledChanged, this);
-    Preferences.ignore(GMPPrefs.getPrefKey(KEY_PLUGIN_VERSION, this._plugin.id),
-                       this.onPrefVersionChanged, this);
+    Preferences.ignore(GMPPrefs.getPrefKey(KEY_PLUGIN_PATH, this._plugin.id),
+                       this.onPrefPathChanged, this);
     if (this._isEME) {
       Preferences.ignore(GMPPrefs.getPrefKey(KEY_EME_ENABLED, this._plugin.id),
                          this.onPrefEnabledChanged, this);
