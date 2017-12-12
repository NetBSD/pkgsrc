$NetBSD: patch-lib_libxview_ttysw_ttytl.c,v 1.1 2017/12/12 20:42:41 hauke Exp $

Nuke harmful K&R style prototype for library function.

--- lib/libxview/ttysw/ttytl.c.orig	1993-06-29 05:17:12.000000000 +0000
+++ lib/libxview/ttysw/ttytl.c
@@ -35,8 +35,6 @@ static char     sccsid[] = "@(#)ttytl.c 
 #include <xview_private/term_impl.h>
 #include <xview_private/charscreen.h>
 
-extern char    *strncpy();
-
 
 /* BUG ALERT: This entire procedure should be rewritten! */
 /* BUG ALERT: No XView prefix */
