$NetBSD: patch-mozilla_mozglue_build_arm.h,v 1.1 2015/12/03 12:22:27 ryoon Exp $

--- mozilla/mozglue/build/arm.h.orig	2015-11-04 01:56:25.000000000 +0000
+++ mozilla/mozglue/build/arm.h
@@ -76,7 +76,7 @@
 #  endif
 
   // Currently we only have CPU detection for Linux via /proc/cpuinfo
-#  if defined(__linux__) || defined(ANDROID)
+#  if defined(__linux__) || defined(ANDROID) || defined(__NetBSD__)
 #    define MOZILLA_ARM_HAVE_CPUID_DETECTION 1
 #  endif
 
