$NetBSD: patch-perllib_sdf_parse.pl,v 1.1 2025/08/11 20:29:34 schmonz Exp $

Preserve some (not all) of older htmldoc's formatting.

--- perllib/sdf/parse.pl.orig	1999-05-25 03:48:29.000000000 +0000
+++ perllib/sdf/parse.pl
@@ -2131,7 +2131,7 @@ sub SdfHtmldoc {
 # Build the header/footer options for HTMLDOC
 sub SdfHtmldocHFOpts {
 
-    return "";
+    return "--headfootfont times-roman --textfont times-roman";
 }
 
 # delete a file
