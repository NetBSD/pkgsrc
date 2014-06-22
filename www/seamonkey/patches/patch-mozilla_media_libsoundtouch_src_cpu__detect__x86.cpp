$NetBSD: patch-mozilla_media_libsoundtouch_src_cpu__detect__x86.cpp,v 1.3 2014/06/22 08:54:39 ryoon Exp $

--- mozilla/media/libsoundtouch/src/cpu_detect_x86.cpp.orig	2014-06-13 00:45:42.000000000 +0000
+++ mozilla/media/libsoundtouch/src/cpu_detect_x86.cpp
@@ -130,7 +130,9 @@ uint detectCPUextensions(void)
 #endif
 
     return res & ~_dwDisabledISA;
-
+#elif defined(__GNUC__)
+    // No cpuid.h --> no cpuid support
+    return 0;
 #else
 
 /// One of these is true:
