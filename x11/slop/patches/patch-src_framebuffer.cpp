$NetBSD: patch-src_framebuffer.cpp,v 1.1 2018/07/28 15:19:59 nia Exp $

error: 'XDestroyImage' was not declared in this scope

--- src/framebuffer.cpp.orig	2018-04-23 07:56:02.000000000 +0000
+++ src/framebuffer.cpp
@@ -1,3 +1,4 @@
+#include <X11/Xutil.h>
 #include "framebuffer.hpp"
 
 slop::Framebuffer::Framebuffer( int w, int h ) {
