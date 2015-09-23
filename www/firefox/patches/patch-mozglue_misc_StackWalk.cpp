$NetBSD: patch-mozglue_misc_StackWalk.cpp,v 1.1 2015/09/23 06:44:42 ryoon Exp $

--- mozglue/misc/StackWalk.cpp.orig	2015-08-24 21:53:17.000000000 +0000
+++ mozglue/misc/StackWalk.cpp
@@ -898,7 +898,7 @@ FramePointerStackWalk(MozWalkStackCallba
         (long(next) & 3)) {
       break;
     }
-#if (defined(__ppc__) && defined(XP_MACOSX)) || defined(__powerpc64__)
+#if (defined(__ppc__) && defined(XP_DARWIN)) || defined(__powerpc64__)
     // ppc mac or powerpc64 linux
     void* pc = *(bp + 2);
     bp += 3;
