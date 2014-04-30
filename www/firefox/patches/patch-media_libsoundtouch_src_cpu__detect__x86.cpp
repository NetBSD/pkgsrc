$NetBSD: patch-media_libsoundtouch_src_cpu__detect__x86.cpp,v 1.5 2014/04/30 15:07:18 ryoon Exp $

--- media/libsoundtouch/src/cpu_detect_x86.cpp.orig	2014-04-18 02:03:48.000000000 +0000
+++ media/libsoundtouch/src/cpu_detect_x86.cpp
@@ -130,7 +130,9 @@ uint detectCPUextensions(void)
 #endif
 
     return res & ~_dwDisabledISA;
-
+#elif defined(__GNUC__)
+    // No cpuid.h --> no cpuid support
+    return 0;
 #else
 
 /// One of these is true:
