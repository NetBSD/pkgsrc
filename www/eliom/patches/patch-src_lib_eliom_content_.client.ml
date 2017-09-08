$NetBSD: patch-src_lib_eliom_content_.client.ml,v 1.1 2017/09/08 17:14:34 jaapb Exp $

Keycode does not exist any longer
--- src/lib/eliom_content_.client.ml.orig	2017-02-07 15:42:18.000000000 +0000
+++ src/lib/eliom_content_.client.ml
@@ -573,8 +573,7 @@ module Html = struct
         elt##.onscroll := (bool_cb f)
       let onreturn elt f =
         let f ev =
-          let key = ev##.keyCode in
-          if key = Keycode.return then f ev;
+          if Dom_html.Keyboard_code.(of_event ev = Enter) then f ev;
           true in
         onkeydown elt f
       let onchange elt f =
