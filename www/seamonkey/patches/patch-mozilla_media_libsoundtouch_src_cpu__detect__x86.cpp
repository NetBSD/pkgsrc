$NetBSD: patch-mozilla_media_libsoundtouch_src_cpu__detect__x86.cpp,v 1.2 2013/07/12 12:24:10 ryoon Exp $

--- mozilla/media/libsoundtouch/src/cpu_detect_x86.cpp.orig	2013-06-20 04:35:15.000000000 +0000
+++ mozilla/media/libsoundtouch/src/cpu_detect_x86.cpp
@@ -131,6 +131,9 @@ uint detectCPUextensions(void)
 
     return res & ~_dwDisabledISA;
 
+#elif defined(__GNUC__)
+    // No cpuid.h --> no cpuid support
+    return 0;
 #else
 
 /// One of these is true:
