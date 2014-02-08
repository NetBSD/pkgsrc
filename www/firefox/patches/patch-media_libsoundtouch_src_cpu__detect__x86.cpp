$NetBSD: patch-media_libsoundtouch_src_cpu__detect__x86.cpp,v 1.3 2014/02/08 09:36:00 ryoon Exp $

--- media/libsoundtouch/src/cpu_detect_x86.cpp.orig	2014-01-28 04:03:54.000000000 +0000
+++ media/libsoundtouch/src/cpu_detect_x86.cpp
@@ -131,6 +131,9 @@ uint detectCPUextensions(void)
 
     return res & ~_dwDisabledISA;
 
+#elif defined(__GNUC__)
+    // No cpuid.h --> no cpuid support
+    return 0;
 #else
 
 /// One of these is true:
