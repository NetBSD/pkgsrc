$NetBSD: patch-lib_Pen.cc,v 1.1 2013/04/29 21:27:15 joerg Exp $

--- lib/Pen.cc.orig	2013-04-28 12:57:35.000000000 +0000
+++ lib/Pen.cc
@@ -36,6 +36,7 @@
 
 #include <assert.h>
 #include <stdio.h>
+#include <stdlib.h>
 
 // #define PENCACHE_DEBUG
 
