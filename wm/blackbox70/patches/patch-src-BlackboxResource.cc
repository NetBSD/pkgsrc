$NetBSD: patch-src-BlackboxResource.cc,v 1.1 2011/11/22 20:02:48 joerg Exp $

--- src/BlackboxResource.cc.orig	2011-11-22 18:43:51.000000000 +0000
+++ src/BlackboxResource.cc
@@ -32,6 +32,7 @@
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
 #include <X11/cursorfont.h>
+#include <strings.h>
 
 
 BlackboxResource::BlackboxResource(const std::string& rc): rc_file(rc) {
