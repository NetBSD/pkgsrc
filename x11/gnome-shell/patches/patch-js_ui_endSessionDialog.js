$NetBSD: patch-js_ui_endSessionDialog.js,v 1.1 2020/11/10 12:06:59 nia Exp $

Remove unsupported "BootLoaderMenu"

--- js/ui/endSessionDialog.js.orig	2020-10-05 18:36:07.893838600 +0000
+++ js/ui/endSessionDialog.js
@@ -230,10 +230,6 @@ class EndSessionDialog extends ModalDial
                       destroyOnClose: false });
 
         this._loginManager = LoginManager.getLoginManager();
-        this._loginManager.canRebootToBootLoaderMenu(
-            (canRebootToBootLoaderMenu, unusedNeedsAuth) => {
-                this._canRebootToBootLoaderMenu = canRebootToBootLoaderMenu;
-            });
 
         this._userManager = AccountsService.UserManager.get_default();
         this._user = this._userManager.get_user(GLib.get_user_name());
@@ -453,23 +449,6 @@ class EndSessionDialog extends ModalDial
                 label,
             });
 
-            // Add Alt "Boot Options" option to the Reboot button
-            if (this._canRebootToBootLoaderMenu && signal === 'ConfirmedReboot') {
-                this._rebootButton = button;
-                this._rebootButtonAlt = this.addButton({
-                    action: () => {
-                        this.close(true);
-                        let signalId = this.connect('closed', () => {
-                            this.disconnect(signalId);
-                            this._confirmRebootToBootLoaderMenu();
-                        });
-                    },
-                    label: C_('button', 'Boot Options'),
-                });
-                this._rebootButtonAlt.visible = false;
-                this._capturedEventId = global.stage.connect('captured-event',
-                    this._onCapturedEvent.bind(this));
-            }
         }
     }
 
