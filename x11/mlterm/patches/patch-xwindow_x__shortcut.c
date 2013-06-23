$NetBSD: patch-xwindow_x__shortcut.c,v 1.1 2013/06/23 06:02:39 tsutsui Exp $

Pull fix from http://mlterm.sf.net/mlterm-3.2.0-fixes.patch
> Fix the bug which disabled mlconfig and mlterm-menu. (enbugged at 3.2.0)

--- xwindow/x_shortcut.c.orig	2013-05-26 02:13:14.000000000 +0000
+++ xwindow/x_shortcut.c
@@ -194,6 +194,7 @@ x_shortcut_init(
 							".exe"
 						#endif
 						) ;
+		button_mask |= (Button1Mask|Button3Mask) ;
 	}
 	else
 	{
