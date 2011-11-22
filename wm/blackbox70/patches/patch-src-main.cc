$NetBSD: patch-src-main.cc,v 1.1 2011/11/22 20:02:48 joerg Exp $

--- src/main.cc.orig	2011-11-22 18:56:19.000000000 +0000
+++ src/main.cc
@@ -35,7 +35,7 @@
 #include "../version.h"
 
 #include <stdio.h>
-
+#include <string.h>
 
 static void showHelp(int exitval) {
   // print version - this should not be localized!
