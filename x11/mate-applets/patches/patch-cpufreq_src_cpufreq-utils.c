$NetBSD: patch-cpufreq_src_cpufreq-utils.c,v 1.1 2019/01/23 15:25:36 youri Exp $

Add NetBSD backend.

--- cpufreq/src/cpufreq-utils.c.orig	2018-01-14 14:48:43.000000000 +0000
+++ cpufreq/src/cpufreq-utils.c
@@ -29,6 +29,11 @@
 #include <unistd.h>
 #include <string.h>
 #include <errno.h>
+#ifdef __NetBSD__
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <err.h>
+#endif
 
 #include "cpufreq-utils.h"
 
@@ -36,6 +41,17 @@
 #include <dbus/dbus-glib.h>
 #endif /* HAVE_POLKIT */
 
+#ifdef __NetBSD__
+guint
+cpufreq_utils_get_n_cpus (void)
+{
+	guint ncpu = -1;
+	size_t len = sizeof(ncpu);
+	if (sysctlbyname("hw.ncpu", &ncpu, &len, NULL, 0) < 0)
+		errx(1, "Failed to get hw.ncpu");
+	return ncpu;
+}
+#else
 guint
 cpufreq_utils_get_n_cpus (void)
 {
@@ -78,6 +94,7 @@ cpufreq_utils_get_n_cpus (void)
 	
 	return 1;
 }
+#endif
 
 void
 cpufreq_utils_display_error (const gchar *message,
