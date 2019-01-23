$NetBSD: patch-cpufreq_src_cpufreq-monitor-sysctl.h,v 1.1 2019/01/23 15:25:36 youri Exp $

Add NetBSD sysctl backend, adapted from freebsd ports

--- cpufreq/src/cpufreq-monitor-sysctl.h.orig	2019-01-23 11:12:16.438531424 +0000
+++ cpufreq/src/cpufreq-monitor-sysctl.h
@@ -0,0 +1,48 @@
+/*  Copyright (C) 2001, 2002 Free Software Foundation
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
+ */
+
+#ifndef __CPUFREQ_MONITOR_SYSCTL_H__
+#define __CPUFREQ_MONITOR_SYSCTL_H__
+
+#include <glib-object.h>
+
+#include "cpufreq-monitor.h"
+
+#define TYPE_CPUFREQ_MONITOR_SYSCTL            (cpufreq_monitor_sysctl_get_type ())
+#define CPUFREQ_MONITOR_SYSCTL(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_CPUFREQ_MONITOR_SYSCTL, CPUFreqMonitorSysctl))
+#define CPUFREQ_MONITOR_SYSCTL_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass), TYPE_CPUFREQ_MONITOR_SYSCTL, CPUFreqMonitorSysctlClass))
+#define IS_CPUFREQ_MONITOR_SYSCTL(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_CPUFREQ_MONITOR_SYSCTL))
+#define IS_CPUFREQ_MONITOR_SYSCTL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_CPUFREQ_MONITOR_SYSCTL))
+#define CPUFREQ_MONITOR_SYSCTL_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_CPUFREQ_MONITOR_SYSCTL, CPUFreqMonitorSysctlClass))
+
+typedef struct _CPUFreqMonitorSysctl      CPUFreqMonitorSysctl;
+typedef struct _CPUFreqMonitorSysctlClass CPUFreqMonitorSysctlClass;
+
+struct _CPUFreqMonitorSysctl {
+	   CPUFreqMonitor parent;
+};
+
+struct _CPUFreqMonitorSysctlClass {
+	   CPUFreqMonitorClass parent_class;
+};
+
+GType           cpufreq_monitor_sysctl_get_type (void) G_GNUC_CONST;
+CPUFreqMonitor *cpufreq_monitor_sysctl_new      (guint cpu);
+
+#endif /* __CPUFREQ_MONITOR_SYSCTL_H__ */
