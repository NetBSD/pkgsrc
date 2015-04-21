$NetBSD: patch-libxfcegui4_dialogs.c,v 1.1 2015/04/21 08:56:43 jperkin Exp $

Fix build for OS X.
--- libxfcegui4/dialogs.c.orig	2012-04-28 20:10:43.000000000 +0000
+++ libxfcegui4/dialogs.c
@@ -64,6 +64,7 @@
 
 #ifdef HAVE__NSGETENVIRON
 /* for support under apple/darwin */
+#include <crt_externs.h>
 #define environ (*_NSGetEnviron())
 #elif !HAVE_DECL_ENVIRON
 /* try extern if environ is not defined in unistd.h */
