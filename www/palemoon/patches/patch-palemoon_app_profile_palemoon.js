$NetBSD: patch-palemoon_app_profile_palemoon.js,v 1.3 2024/08/03 08:54:26 nia Exp $

Modify some defaults to provide a better initial experience on NetBSD.

--- palemoon/app/profile/palemoon.js.orig	2024-07-10 12:35:09.000000000 +0000
+++ palemoon/app/profile/palemoon.js
@@ -1255,3 +1255,9 @@ pref("status4evar.status.toolbar.maxLeng
 
 pref("status4evar.status.popup.invertMirror", false);
 pref("status4evar.status.popup.mouseMirror", true);
+
+// ** pkgsrc specific preferences **
+
+// Otherwise handshake fails on some sites,
+// see various posts on the pale moon forums
+pref("security.tls.hello_downgrade_check", false);
