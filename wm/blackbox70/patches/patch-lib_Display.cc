$NetBSD: patch-lib_Display.cc,v 1.1 2013/04/29 21:27:15 joerg Exp $

--- lib/Display.cc.orig	2013-04-28 12:56:05.000000000 +0000
+++ lib/Display.cc
@@ -31,7 +31,7 @@
 #include <assert.h>
 #include <fcntl.h>
 #include <stdio.h>
-
+#include <stdlib.h>
 
 namespace bt {
 
