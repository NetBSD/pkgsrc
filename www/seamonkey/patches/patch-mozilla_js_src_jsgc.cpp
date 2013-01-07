$NetBSD: patch-mozilla_js_src_jsgc.cpp,v 1.3 2013/01/07 21:55:30 ryoon Exp $

--- mozilla/js/src/jsgc.cpp.orig	2012-11-18 10:19:39.000000000 +0000
+++ mozilla/js/src/jsgc.cpp
@@ -2865,8 +2865,12 @@ GetCPUCount()
         GetSystemInfo(&sysinfo);
         ncpus = unsigned(sysinfo.dwNumberOfProcessors);
 # else
+#  ifdef _SC_NPROCESSORS_ONLN
         long n = sysconf(_SC_NPROCESSORS_ONLN);
         ncpus = (n > 0) ? unsigned(n) : 1;
+#  else
+       ncpus = 1;
+#  endif
 # endif
     }
     return ncpus;
