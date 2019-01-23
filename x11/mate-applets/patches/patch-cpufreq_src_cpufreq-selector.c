$NetBSD: patch-cpufreq_src_cpufreq-selector.c,v 1.1 2019/01/23 15:25:36 youri Exp $

Add NetBSD backend.

--- cpufreq/src/cpufreq-selector.c.orig	2019-01-23 11:23:52.583081163 +0000
+++ cpufreq/src/cpufreq-selector.c
@@ -18,7 +18,12 @@
  */
 
 #include <config.h>
+#ifdef __Linux__
 #include <sys/sysinfo.h>
+#else
+#include "cpufreq-utils.h"
+#define get_nprocs cpufreq_utils_get_n_cpus
+#endif
 
 #ifdef HAVE_POLKIT
 #include <dbus/dbus-glib.h>
