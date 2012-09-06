$NetBSD: patch-mozilla_js_src_jsgc.cpp,v 1.1 2012/09/06 12:08:52 ryoon Exp $

--- mozilla/js/src/jsgc.cpp.orig	2012-08-27 04:49:16.000000000 +0000
+++ mozilla/js/src/jsgc.cpp
@@ -2635,8 +2635,12 @@ GetCPUCount()
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
