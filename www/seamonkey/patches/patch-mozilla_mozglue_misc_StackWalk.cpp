$NetBSD: patch-mozilla_mozglue_misc_StackWalk.cpp,v 1.1 2015/10/02 22:49:36 ryoon Exp $

--- mozilla/mozglue/misc/StackWalk.cpp.orig	2015-09-25 07:36:02.000000000 +0000
+++ mozilla/mozglue/misc/StackWalk.cpp
@@ -903,7 +903,7 @@ FramePointerStackWalk(MozWalkStackCallba
         (long(next) & 3)) {
       break;
     }
-#if (defined(__ppc__) && defined(XP_MACOSX)) || defined(__powerpc64__)
+#if (defined(__ppc__) && defined(XP_DARWIN)) || defined(__powerpc64__)
     // ppc mac or powerpc64 linux
     void* pc = *(bp + 2);
     bp += 3;
