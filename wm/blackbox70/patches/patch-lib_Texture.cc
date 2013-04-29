$NetBSD: patch-lib_Texture.cc,v 1.1 2013/04/29 21:27:15 joerg Exp $

--- lib/Texture.cc.orig	2013-04-28 12:59:39.000000000 +0000
+++ lib/Texture.cc
@@ -31,7 +31,7 @@
 
 #include <X11/Xlib.h>
 #include <ctype.h>
-
+#include <stdlib.h>
 
 void bt::Texture::setColor1(const bt::Color &new_color) {
   c1 = new_color;
