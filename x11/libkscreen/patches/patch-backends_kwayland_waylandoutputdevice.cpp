$NetBSD: patch-backends_kwayland_waylandoutputdevice.cpp,v 1.1 2023/11/14 03:54:55 gutteridge Exp $

Explicitly include cmath, for compilers that are more exacting, e.g., GCC 7.5.

--- backends/kwayland/waylandoutputdevice.cpp.orig	2023-10-24 12:56:57.000000000 +0000
+++ backends/kwayland/waylandoutputdevice.cpp
@@ -16,6 +16,7 @@
 
 #include <wayland-server-protocol.h>
 
+#include <cmath>
 #include <utility>
 
 using namespace KScreen;
