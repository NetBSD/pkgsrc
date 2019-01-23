$NetBSD: patch-cpufreq_src_cpufreq-monitor-factory.c,v 1.1 2019/01/23 15:25:36 youri Exp $

Add NetBSD support.

--- cpufreq/src/cpufreq-monitor-factory.c.orig	2018-01-14 14:48:43.000000000 +0000
+++ cpufreq/src/cpufreq-monitor-factory.c
@@ -25,11 +25,18 @@
 
 #include <glib.h>
 #include <glib/gi18n.h>
+#ifdef __NetBSD__
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#endif
 
 #include "cpufreq-applet.h"
 #include "cpufreq-utils.h"
 #include "cpufreq-monitor-sysfs.h"
 #include "cpufreq-monitor-procfs.h"
+#ifdef __NetBSD__
+#include "cpufreq-monitor-sysctl.h"
+#endif
 #include "cpufreq-monitor-cpuinfo.h"
 #ifdef HAVE_LIBCPUFREQ
 #include "cpufreq-monitor-libcpufreq.h"
@@ -40,6 +47,7 @@ CPUFreqMonitor *
 cpufreq_monitor_factory_create_monitor (guint cpu)
 {
 	   CPUFreqMonitor *monitor = NULL;
+#ifndef __NetBSD__
 
 #ifdef HAVE_LIBCPUFREQ
 	   monitor = cpufreq_monitor_libcpufreq_new (cpu);
@@ -63,6 +71,19 @@ cpufreq_monitor_factory_create_monitor (
 		   
 		   monitor = cpufreq_monitor_cpuinfo_new (cpu);
 	   }
+#else
+	   size_t len;
+
+	   if (sysctlbyname ("machdep.est.frequency.current", NULL, &len, NULL, 0) == 0) {
+		   monitor = cpufreq_monitor_sysctl_new (cpu);
+	   } else {
+		   cpufreq_utils_display_error (_("CPU frequency scaling unsupported"),
+				   		_("You will not be able to modify the frequency of your machine.  "
+						"Your machine may be misconfigured or not have hardware support "
+						"for CPU frequency scaling."));
+		   monitor = cpufreq_monitor_cpuinfo_new (cpu);
+	   }
+#endif /* __NetBSD__ */
 	   
 	   return monitor;
 }
