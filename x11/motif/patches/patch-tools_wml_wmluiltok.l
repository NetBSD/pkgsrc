$NetBSD: patch-tools_wml_wmluiltok.l,v 1.1 2012/11/10 17:10:11 ryoon Exp $

--- tools/wml/wmluiltok.l.orig	2012-10-22 14:50:39.000000000 +0000
+++ tools/wml/wmluiltok.l
@@ -55,6 +55,8 @@
 
 %a 9999						/* transitions */
 
+%option main
+
 %{
 
 #include <stdio.h>
