$NetBSD: patch-cpufreq_src_cpufreq-monitor-cpuinfo.c,v 1.1 2019/01/23 15:25:36 youri Exp $

Add NetBSD support.

--- cpufreq/src/cpufreq-monitor-cpuinfo.c.orig	2018-01-14 14:48:43.000000000 +0000
+++ cpufreq/src/cpufreq-monitor-cpuinfo.c
@@ -29,6 +29,12 @@
 #include <string.h>
 #include <stdio.h>
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <err.h>
+#endif
+
 #include "cpufreq-monitor-cpuinfo.h"
 #include "cpufreq-utils.h"
 
@@ -64,15 +70,20 @@ cpufreq_monitor_cpuinfo_new (guint cpu)
 static gboolean
 cpufreq_monitor_cpuinfo_run (CPUFreqMonitor *monitor)
 {
+#ifndef __NetBSD__
         gchar *file;
         gchar                   **lines;
         gchar *buffer = NULL;
         gchar                    *p;
+#else
+	size_t len;
+#endif
         gint                      cpu, i;
         gint cur_freq, max_freq;
         gchar *governor;
         GError *error = NULL;
 
+#ifndef __NetBSD__
         file = g_strdup ("/proc/cpuinfo");
         if (!cpufreq_file_get_contents (file, &buffer, NULL, &error)) {
                 g_warning ("%s", error->message);
@@ -117,9 +128,17 @@ cpufreq_monitor_cpuinfo_run (CPUFreqMoni
 
         g_strfreev (lines);
         g_free (buffer);
+#else
+	len = sizeof(cpu);
+	if (sysctlbyname("kern.clockrate", &cpu, &len, NULL, 0) < 1) {
+		errx(1, "Failed to get kern.clockrate");
+		return FALSE;
+	}
+	printf("got clockrate = %d\n", cpu);
+#endif
            
         governor = g_strdup (_("Frequency Scaling Unsupported"));
-        cur_freq = cpu * 1000;
+        cur_freq = cpu;
         max_freq = cur_freq;
 
         g_object_set (G_OBJECT (monitor),
