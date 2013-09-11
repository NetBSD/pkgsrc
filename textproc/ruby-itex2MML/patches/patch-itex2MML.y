$NetBSD: patch-itex2MML.y,v 1.1 2013/09/11 15:14:00 taca Exp $

Fix build with bison-3.0

--- itex2MML.y.orig	2010-10-03 07:11:13.000000000 +0000
+++ itex2MML.y
@@ -2,6 +2,8 @@
  *   itex2MML.y last modified 10/2/2010
  */
 
+%parse-param {char **ret_str}
+
 %{
 #include <stdio.h>
 #include <string.h>
@@ -27,7 +29,7 @@
 
  void (*itex2MML_error) (const char * msg) = itex2MML_default_error;
 
- static void yyerror (char * s)
+ static void yyerror (char **ret_str, char * s)
    {
      char * msg = itex2MML_copy3 (s, " at token ", yytext);
      if (itex2MML_error)
