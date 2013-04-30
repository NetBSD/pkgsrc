$NetBSD: patch-src_ImageControl.cc,v 1.1 2013/04/30 22:34:32 joerg Exp $

--- src/ImageControl.cc.orig	2013-04-30 19:20:20.000000000 +0000
+++ src/ImageControl.cc
@@ -34,6 +34,7 @@ extern "C" {
 #  include <ctype.h>
 #endif // HAVE_CTYPE_H
 
+#include <stdlib.h>
 #include <X11/Xlib.h>
 }
 
