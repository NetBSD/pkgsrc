$NetBSD: patch-events.c,v 1.1 2013/03/28 21:40:11 joerg Exp $

--- events.c.orig	2013-03-28 19:14:44.000000000 +0000
+++ events.c
@@ -38,6 +38,8 @@
 
 /* ===== externs ========================================================== */
 
+void CheckOlvwmRC(Display *dpy);
+
 extern void	ReapChildren();
 
 /* ===== globals ========================================================== */
