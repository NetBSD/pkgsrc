$NetBSD: patch-Library_src_HTStyle.c,v 1.1 2018/06/24 16:54:59 adam Exp $

Define application-wide style sheet.

--- Library/src/HTStyle.c.orig	Mon Feb 22 16:10:12 1999
+++ Library/src/HTStyle.c
@@ -18,6 +18,8 @@
 #include "WWWUtil.h"
 #include "HTStyle.h"
 
+PUBLIC HTStyleSheet * styleSheet;
+
 struct _HTStyle {
     char *	name;		/* Style name */
     int		element;	/* Element (if any) that this style applies to */
