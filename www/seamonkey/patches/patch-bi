$NetBSD: patch-bi,v 1.5 2012/09/06 12:08:51 ryoon Exp $

--- mozilla/gfx/angle/src/compiler/osinclude.h.orig	2012-08-27 04:49:10.000000000 +0000
+++ mozilla/gfx/angle/src/compiler/osinclude.h
@@ -16,6 +16,7 @@
 #define ANGLE_OS_WIN
 #elif defined(__APPLE__) || defined(__linux__) || \
       defined(__FreeBSD__) || defined(__OpenBSD__) || \
+      defined(__NetBSD__) || defined(__DragonFly__) || \
       defined(__sun) || defined(ANDROID) || \
       defined(__GLIBC__) || defined(__GNU__)
 #define ANGLE_OS_POSIX
