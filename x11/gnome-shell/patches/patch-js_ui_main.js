$NetBSD: patch-js_ui_main.js,v 1.2 2021/07/03 19:12:10 cirnatdan Exp $

Remove initial-setup and lock screen warning due to unsupported functions

--- js/ui/main.js.orig	2021-06-10 11:33:01.609929600 +0000
+++ js/ui/main.js
@@ -290,12 +290,6 @@ function _initializeUI() {
         }
 
         let credentials = new Gio.Credentials();
-        if (credentials.get_unix_user() === 0) {
-            notify(_('Logged in as a privileged user'),
-                   _('Running a session as a privileged user should be avoided for security reasons. If possible, you should log in as a normal user.'));
-        } else if (sessionMode.showWelcomeDialog) {
-            _handleShowWelcomeScreen();
-        }
 
         if (sessionMode.currentMode !== 'gdm' &&
             sessionMode.currentMode !== 'initial-setup')
@@ -321,29 +315,6 @@ function _handleShowWelcomeScreen() {
 }
 
 async function _handleLockScreenWarning() {
-    const path = '%s/lock-warning-shown'.format(global.userdatadir);
-    const file = Gio.File.new_for_path(path);
-
-    const hasLockScreen = screenShield !== null;
-    if (hasLockScreen) {
-        try {
-            await file.delete_async(0, null);
-        } catch (e) {
-            if (!e.matches(Gio.IOErrorEnum, Gio.IOErrorEnum.NOT_FOUND))
-                logError(e);
-        }
-    } else {
-        try {
-            if (!await file.touch_async())
-                return;
-        } catch (e) {
-            logError(e);
-        }
-
-        notify(
-            _('Screen Lock disabled'),
-            _('Screen Locking requires the GNOME display manager.'));
-    }
 }
 
 function _getStylesheet(name) {
