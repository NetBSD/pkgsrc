$NetBSD: patch-src_kernel.cpp,v 1.1 2022/08/01 18:52:28 wiz Exp $

For strdup().

--- src/kernel.cpp.orig	2004-10-03 12:15:19.000000000 +0000
+++ src/kernel.cpp
@@ -6,6 +6,7 @@
 extern "C" {
 #include <assert.h>
 #include <stdlib.h> // getenv stuff
+#include <string.h>
 #include <unistd.h>
 #include <X11/Xlib.h>
 #include <X11/Xatom.h>
