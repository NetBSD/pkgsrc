$NetBSD: patch-lib_EWMH.cc,v 1.1 2020/06/16 23:47:07 gutteridge Exp $

Needs cstdlib for getenv() and unsetenv().
https://github.com/bbidulock/blackboxwm/pull/31

--- lib/EWMH.cc.orig	2020-02-11 12:24:59.840000000 +0000
+++ lib/EWMH.cc
@@ -28,6 +28,7 @@
 #include <X11/Xlib.h>
 
 #include <cstdio>
+#include <cstdlib>
 #include <cstring>
 
 
