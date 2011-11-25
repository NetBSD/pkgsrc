$NetBSD: patch-src_FbTk_XFontImp.cc,v 1.1 2011/11/25 22:25:31 joerg Exp $

--- src/FbTk/XFontImp.cc.orig	2011-11-25 17:38:54.000000000 +0000
+++ src/FbTk/XFontImp.cc
@@ -29,6 +29,7 @@
 #include <X11/Xutil.h>
 
 #include <iostream>
+#include <cstdlib>
 #include <new>
 #ifdef HAVE_CSTDIO
   #include <cstdio>
