$NetBSD: patch-src_TextSink.c,v 1.1 2022/04/04 12:42:19 riastradh Exp $

Fix ctype(3) abuse.

--- src/TextSink.c.orig	2021-03-27 17:40:21.000000000 +0000
+++ src/TextSink.c
@@ -1251,7 +1251,7 @@ _XawTextSinkAddProperty(XawTextPropertyL
 	weight = asterisk;
     if (property->slant != NULLQUARK) {
 	slant = XrmQuarkToString(property->slant);
-	if (toupper(*slant) != 'R')
+	if (toupper((unsigned char)*slant) != 'R')
 	    slant = asterisk;	/* X defaults to italics, so, don't
 				   care in resolving between `I' and `O' */
     }
