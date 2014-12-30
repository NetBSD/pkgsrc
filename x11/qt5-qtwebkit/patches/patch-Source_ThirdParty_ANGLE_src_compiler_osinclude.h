$NetBSD: patch-Source_ThirdParty_ANGLE_src_compiler_osinclude.h,v 1.1 2014/12/30 17:23:47 adam Exp $

* Add NetBSD support
* Add DragonFly support

--- Source/ThirdParty/ANGLE/src/compiler/osinclude.h.orig	2013-11-27 01:01:50.000000000 +0000
+++ Source/ThirdParty/ANGLE/src/compiler/osinclude.h
@@ -18,7 +18,7 @@
       defined(__FreeBSD__) || defined(__OpenBSD__) || \
       defined(__sun) || defined(ANDROID) || \
       defined(__GLIBC__) || defined(__GNU__) || \
-      defined(__QNX__)
+      defined(__QNX__) || defined(__NetBSD__) || defined(__DragonFly__)
 #define ANGLE_OS_POSIX
 #else
 #error Unsupported platform.
