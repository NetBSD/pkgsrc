$NetBSD: patch-src_cout.c,v 1.1 2014/11/25 15:05:16 joerg Exp $

--- src/cout.c.orig	2014-11-23 15:12:18.000000000 +0000
+++ src/cout.c
@@ -45,7 +45,7 @@ WriteCHdrVMods(FILE *file,Display *dpy,X
 {
 register int i,nOut;
 
-    if ((!xkb)||(!xkb->names)||(!xkb->names->vmods))
+    if ((!xkb)||(!xkb->names))
 	return False;
     for (i=nOut=0;i<XkbNumVirtualMods;i++) {
 	if (xkb->names->vmods[i]!=None) {
