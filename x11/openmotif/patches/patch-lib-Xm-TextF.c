$NetBSD: patch-lib-Xm-TextF.c,v 1.1.1.1 2000/10/29 16:17:13 mjl Exp $

--- lib/Xm/TextF.c.orig	Sun Oct 29 15:43:15 2000
+++ lib/Xm/TextF.c	Sun Oct 29 15:45:35 2000
@@ -84,7 +84,7 @@
 #include <Xm/PrintSP.h>         /* for XmIsPrintShell */
 
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined (__NetBSD__)
 /*
  * Modification by Integrated Computer Solutions, Inc.  May 2000
  *
