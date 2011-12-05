$NetBSD: patch-src_main.cpp,v 1.1 2011/12/05 22:56:58 joerg Exp $

--- src/main.cpp.orig	2011-12-05 20:33:30.000000000 +0000
+++ src/main.cpp
@@ -13,6 +13,7 @@ extern "C" {
 #include <X11/Xlib.h>
 }
 
+#include <cstring>
 #include <iostream>
 #include <string>
 #include <sstream>
