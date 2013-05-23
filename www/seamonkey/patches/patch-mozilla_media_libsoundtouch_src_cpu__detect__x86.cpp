$NetBSD: patch-mozilla_media_libsoundtouch_src_cpu__detect__x86.cpp,v 1.1 2013/05/23 13:25:30 ryoon Exp $

--- mozilla/media/libsoundtouch/src/cpu_detect_x86.cpp.orig	2013-05-03 03:08:05.000000000 +0000
+++ mozilla/media/libsoundtouch/src/cpu_detect_x86.cpp
@@ -101,7 +101,7 @@ uint detectCPUextensions(void)
  
     uint res = 0;
  
-#if defined(__GNUC__)
+#if defined(__GNUC__) && defined(HAVE_CPUID_H)
     // GCC version of cpuid. Requires GCC 4.3.0 or later for __cpuid intrinsic support.
     uint eax, ebx, ecx, edx;  // unsigned int is the standard type. uint is defined by the compiler and not guaranteed to be portable.
 
@@ -112,6 +112,9 @@ uint detectCPUextensions(void)
     if (edx & bit_SSE)  res = res | SUPPORT_SSE;
     if (edx & bit_SSE2) res = res | SUPPORT_SSE2;
 
+#elif defined(__GNUC__)
+    // No cpuid.h --> no cpuid support
+    return 0;
 #else
     // Window / VS version of cpuid. Notice that Visual Studio 2005 or later required 
     // for __cpuid intrinsic support.
