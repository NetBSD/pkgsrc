$NetBSD: patch-js_ui_main.js,v 1.1 2021/06/03 15:11:05 cirnatdan Exp $

Remove usages of unsupported functions:
- Gio.Credentials.get_unix_user
- file.touch_async

--- js/ui/main.js.orig	2021-03-20 12:17:01.417523000 +0000
+++ js/ui/main.js
@@ -289,19 +289,11 @@ function _initializeUI() {
             });
         }
 
-        let credentials = new Gio.Credentials();
-        if (credentials.get_unix_user() === 0) {
-            notify(_('Logged in as a privileged user'),
-                   _('Running a session as a privileged user should be avoided for security reasons. If possible, you should log in as a normal user.'));
-        } else if (sessionMode.currentMode !== 'gdm' &&
+        if (sessionMode.currentMode !== 'gdm' &&
                    sessionMode.currentMode !== 'initial-setup') {
             _handleShowWelcomeScreen();
         }
 
-        if (sessionMode.currentMode !== 'gdm' &&
-            sessionMode.currentMode !== 'initial-setup')
-            _handleLockScreenWarning();
-
         LoginManager.registerSessionWithGDM();
 
         let perfModuleName = GLib.getenv("SHELL_PERF_MODULE");
@@ -324,7 +316,7 @@ function _handleShowWelcomeScreen() {
 async function _handleLockScreenWarning() {
     const path = '%s/lock-warning-shown'.format(global.userdatadir);
     const file = Gio.File.new_for_path(path);
-
+return;
     const hasLockScreen = screenShield !== null;
     if (hasLockScreen) {
         try {
