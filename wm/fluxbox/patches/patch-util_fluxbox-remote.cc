$NetBSD: patch-util_fluxbox-remote.cc,v 1.1 2017/03/07 13:22:28 joerg Exp $

--- util/fluxbox-remote.cc.orig	2017-02-28 00:35:38.013459100 +0000
+++ util/fluxbox-remote.cc
@@ -73,7 +73,7 @@ int main(int argc, char **argv) {
     if (strcmp(cmd, "result") == 0) {
         XTextProperty text_prop;
         if (XGetTextProperty(disp, root, &text_prop, atom_result) != 0
-            && text_prop.value > 0
+            && text_prop.value
             && text_prop.nitems > 0) {
 
             printf("%s", text_prop.value);
