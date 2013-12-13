$NetBSD: patch-qtwebkit_Source_ThirdParty_ANGLE_src_compiler_osinclude.h,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Add NetBSD support
* Add DragonFly support

--- qtwebkit/Source/ThirdParty/ANGLE/src/compiler/osinclude.h.orig	2013-11-27 01:01:50.000000000 +0000
+++ qtwebkit/Source/ThirdParty/ANGLE/src/compiler/osinclude.h
@@ -18,7 +18,7 @@
       defined(__FreeBSD__) || defined(__OpenBSD__) || \
       defined(__sun) || defined(ANDROID) || \
       defined(__GLIBC__) || defined(__GNU__) || \
-      defined(__QNX__)
+      defined(__QNX__) || defined(__NetBSD__) || defined(__DragonFly__)
 #define ANGLE_OS_POSIX
 #else
 #error Unsupported platform.
