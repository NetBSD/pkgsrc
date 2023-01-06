$NetBSD: patch-daemon_core.cpp,v 1.3 2023/01/06 02:35:47 gutteridge Exp $

Fix SunOS builds.

--- daemon/core.cpp.orig	2022-11-05 08:17:16.000000000 +0000
+++ daemon/core.cpp
@@ -59,6 +59,10 @@
 
 #include "core.h"
 
+#ifndef LOG_MAKEPRI
+#define LOG_MAKEPRI(fac, pri)    ((fac) | (pri))
+#endif
+
 
 enum
 {
