$NetBSD: patch-cpufreq_src_cpufreq-monitor-sysctl.c,v 1.1 2019/01/23 15:25:36 youri Exp $

Add NetBSD support, adapted from freebsd ports.

--- cpufreq/src/cpufreq-monitor-sysctl.c.orig	2019-01-23 13:06:18.405523935 +0000
+++ cpufreq/src/cpufreq-monitor-sysctl.c
@@ -0,0 +1,182 @@
+/*
+ * Copyright (C) 2001, 2002 Free Software Foundation
+ *
+ *  This library is free software; you can redistribute it and/or
+ *  modify it under the terms of the GNU General Public
+ *  License as published by the Free Software Foundation; either
+ *  version 2 of the License, or (at your option) any later version.
+ *
+ *  This library is distributed in the hope that it will be useful,
+ *  but WITHOUT ANY WARRANTY; without even the implied warranty of
+ *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+ *  General Public License for more details.
+ *
+ *  You should have received a copy of the GNU General Public
+ *  License along with this library; if not, write to the Free
+ *  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
+ *
+ * Authors : Joe Marcus Clarke <marcus@FreeBSD.org>
+ * 	     Youri Mouton <youri@NetBSD.org>
+ */
+
+#include <glib.h>
+#include <glib/gi18n.h>
+
+#include <string.h>
+
+#ifdef __NetBSD__
+#include <errno.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
+
+#include "cpufreq-monitor-sysctl.h"
+
+#define PARENT_TYPE TYPE_CPUFREQ_MONITOR
+
+#define CPUFREQ_MONITOR_GET_PROTECTED(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), PARENT_TYPE, CPUFreqMonitorProtected))
+
+static void     cpufreq_monitor_sysctl_class_init                (CPUFreqMonitorSysctlClass *klass);
+
+static gboolean     cpufreq_monitor_sysctl_run                       (CPUFreqMonitor *monitor);
+static GList   *cpufreq_monitor_sysctl_get_available_frequencies (CPUFreqMonitor *monitor);
+static GList   *cpufreq_monitor_sysctl_get_available_governors   (CPUFreqMonitor *monitor);
+
+static gboolean cpufreq_monitor_sysctl_get                       (gpointer gdata);
+
+G_DEFINE_TYPE (CPUFreqMonitorSysctl, cpufreq_monitor_sysctl, CPUFREQ_TYPE_MONITOR)
+
+static void
+cpufreq_monitor_sysctl_init (CPUFreqMonitorSysctl *monitor)
+{
+}
+
+static void
+cpufreq_monitor_sysctl_class_init (CPUFreqMonitorSysctlClass *klass)
+{
+	CPUFreqMonitorClass *monitor_class = CPUFREQ_MONITOR_CLASS (klass);
+
+	monitor_class->run = cpufreq_monitor_sysctl_run;
+	monitor_class->get_available_frequencies = cpufreq_monitor_sysctl_get_available_frequencies;
+	monitor_class->get_available_governors = cpufreq_monitor_sysctl_get_available_governors;
+}
+
+CPUFreqMonitor *
+cpufreq_monitor_sysctl_new (guint cpu)
+{
+	   CPUFreqMonitorSysctl *monitor;
+
+	   monitor = g_object_new (TYPE_CPUFREQ_MONITOR_SYSCTL, "cpu", cpu, NULL);
+
+	   return CPUFREQ_MONITOR (monitor);
+}
+
+static gboolean
+cpufreq_monitor_sysctl_run (CPUFreqMonitor *monitor)
+{
+	   gint                     fmax, fmin, ifreq;
+	   gchar                   *governor;
+	   size_t                   len;
+	   gchar                   *freq_oid;
+	   guint                    mon_cpu;
+	   GList                   *list;
+
+	   list = cpufreq_monitor_sysctl_get_available_frequencies (CPUFREQ_MONITOR (monitor));
+
+	   fmax = (int)strtol(g_list_first(list), (char **)NULL, 10);
+	   if (errno)
+		   errx(1, "Failed to strtol for fmax");
+	   fmin = (int)strtol(g_list_last(list), (char **)NULL, 10);
+	   if (errno)
+		   errx(1, "Failed to strtol for fmin");
+
+	   g_list_foreach (list, (GFunc) g_free, NULL);
+	   g_list_free (list);
+
+	   g_object_get (G_OBJECT (monitor), "cpu", &mon_cpu, NULL);
+	   len = sizeof (ifreq);
+	   freq_oid = g_strdup_printf ("machdep.est.frequency.current", 0);
+
+	   if (sysctlbyname (freq_oid, &ifreq, &len, NULL, 0) == -1) {
+		   	 errx(1, "failed to get machdep.est.frequency.current: %s\n", strerror(errno));
+	       		 g_free (freq_oid);
+	       		 return FALSE;
+	   }
+
+	   if (ifreq == fmax)
+	       		 governor = g_strdup ("performance");
+	   else if (ifreq == fmin)
+	       		 governor = g_strdup ("economy");
+	   else
+	       		 governor = g_strdup ("userspace");
+
+	   g_object_set (G_OBJECT (monitor),
+			 "online", TRUE,
+			 "governor", governor,
+			 "frequency", ifreq,
+			 "max-frequency", fmax,
+			 NULL);
+
+	   g_free (governor);
+
+	   return TRUE;
+}
+
+static GList *
+cpufreq_monitor_sysctl_get_available_frequencies (CPUFreqMonitor *monitor)
+{
+	   gchar *levels_oid, *levels;
+	   gchar **levelsp, **l;
+	   GList *list = NULL;
+	   gint mib[4];
+	   guint mon_cpu;
+	   size_t len;
+
+	   g_object_get (G_OBJECT (monitor), "cpu", &mon_cpu, NULL);
+
+	   levels_oid = g_strdup_printf ("machdep.est.frequency.available",
+	   	0);
+	   len = 4;
+	   sysctlnametomib (levels_oid, mib, &len);
+	   len = sizeof (levels);
+	   g_free (levels_oid);
+
+	   if (sysctl (mib, 4, NULL, &len, NULL, 0) == -1)
+			 return NULL;
+
+	   levels = g_malloc (len);
+	   if (sysctl (mib, 4, levels, &len, NULL, 0) == -1)
+	   {
+	        	 g_free(levels);
+	       		 return NULL;
+	   }
+
+	   levelsp = g_strsplit (levels, " ", 0);
+	   g_free (levels);
+
+	   for (l = levelsp; l && *l; l++) {
+		   	int freq = (int)strtol(*l, (char **)NULL, 0);
+			if (errno)
+				errx(1, "Failed to strtol freq levels");
+			freq *= 1000;
+			char *f = g_strdup_printf("%d", freq);
+			list = g_list_append(list, f);
+	   }
+	   
+
+	   g_strfreev (levelsp);
+
+	   return (list);
+}
+
+static GList *
+cpufreq_monitor_sysctl_get_available_governors (CPUFreqMonitor *monitor)
+{
+	GList *list = NULL;
+
+	list = g_list_prepend (list, g_strdup ("performance"));
+	list = g_list_prepend (list, g_strdup ("userspace"));
+	list = g_list_prepend (list, g_strdup ("economy"));
+
+	return list;
+}
+#endif /* __NetBSD__ */
