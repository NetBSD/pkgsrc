$NetBSD: patch-mozglue_build_arm.h,v 1.2 2016/06/16 12:08:21 ryoon Exp $

* Support NetBSD/earm

--- mozglue/build/arm.h.orig	2015-09-29 21:45:02.000000000 +0000
+++ mozglue/build/arm.h
@@ -76,7 +76,7 @@
 #  endif
 
   // Currently we only have CPU detection for Linux via /proc/cpuinfo
-#  if defined(__linux__) || defined(ANDROID)
+#  if defined(__linux__) || defined(ANDROID) || defined(__NetBSD__)
 #    define MOZILLA_ARM_HAVE_CPUID_DETECTION 1
 #  endif
 
