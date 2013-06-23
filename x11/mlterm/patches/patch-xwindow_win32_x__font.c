$NetBSD: patch-xwindow_win32_x__font.c,v 1.1 2013/06/23 06:02:39 tsutsui Exp $

Pull fix from http://mlterm.sf.net/mlterm-3.2.0-fixes.patch
> Fix the error message in the failure of loading US-ASCII font.

--- xwindow/win32/x_font.c.orig	2013-05-26 02:13:12.000000000 +0000
+++ xwindow/win32/x_font.c
@@ -862,8 +862,17 @@ x_font_get_encoding_names(
 	mkf_charset_t  cs
 	)
 {
-	static char *  csnames[] = { "iso8859-1" } ;	/* dummy */
-	
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
 	return  csnames ;
 }
 
