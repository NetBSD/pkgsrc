$NetBSD: patch-src-main.cc,v 1.2 2013/04/29 21:27:15 joerg Exp $

--- src/main.cc.orig	2005-01-03 09:42:57.000000000 +0000
+++ src/main.cc
@@ -35,7 +35,8 @@
 #include "../version.h"
 
 #include <stdio.h>
-
+#include <stdlib.h>
+#include <string.h>
 
 static void showHelp(int exitval) {
   // print version - this should not be localized!
