$NetBSD: patch-src_ImageControl.cc,v 1.1 2013/04/29 21:31:13 joerg Exp $

--- src/ImageControl.cc.orig	2013-04-29 20:13:00.000000000 +0000
+++ src/ImageControl.cc
@@ -34,6 +34,7 @@ extern "C" {
 #  include <ctype.h>
 #endif // HAVE_CTYPE_H
 
+#include <stdlib.h>
 #include <X11/Xlib.h>
 }
 
