$NetBSD: patch-src-ScreenResource.cc,v 1.1 2011/11/22 20:02:48 joerg Exp $

--- src/ScreenResource.cc.orig	2011-11-22 18:52:35.000000000 +0000
+++ src/ScreenResource.cc
@@ -32,7 +32,7 @@
 #include <Resource.hh>
 
 #include <assert.h>
-
+#include <strings.h>
 
 static const int iconify_width  = 9;
 static const int iconify_height = 9;
