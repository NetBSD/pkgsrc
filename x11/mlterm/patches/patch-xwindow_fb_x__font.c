$NetBSD: patch-xwindow_fb_x__font.c,v 1.1 2013/06/23 06:02:39 tsutsui Exp $

Pull fix from http://mlterm.sf.net/mlterm-3.2.0-fixes.patch
> Fix the error message in the failure of loading US-ASCII font.

--- xwindow/fb/x_font.c.orig	2013-05-26 02:13:13.000000000 +0000
+++ xwindow/fb/x_font.c
@@ -1066,7 +1066,18 @@ x_font_get_encoding_names(
 	mkf_charset_t  cs
 	)
 {
-	return  NULL ;
+	static char *  csnames[] = { NULL , NULL , } ;	/* dummy */
+
+	if( cs == ISO10646_UCS4_1)
+	{
+		csnames[0] = "iso10646-1" ;
+	}
+	else
+	{
+		csnames[0] = "iso8859" ;
+	}
+
+	return  csnames ;
 }
 
 /* Return written size */
