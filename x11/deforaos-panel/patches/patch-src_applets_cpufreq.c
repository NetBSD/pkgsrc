$NetBSD: patch-src_applets_cpufreq.c,v 1.1 2018/04/12 16:09:50 bouyer Exp $
Fix systctl name on newer NetBSD
Avoid updating display when not needed.

--- src/applets/cpufreq.c.orig	2016-01-12 02:32:16.000000000 +0100
+++ src/applets/cpufreq.c	2018-04-10 19:27:01.584667727 +0200
@@ -43,6 +43,7 @@
 	int min;
 	int max;
 	int step;
+	int actual;
 #if defined(__FreeBSD__) || defined(__NetBSD__)
 	char const * name;
 #endif
@@ -101,6 +102,9 @@
 	else if(sysctlbyname("machdep.frequency.available", &freq, &freqsize,
 				NULL, 0) == 0)
 		p = "machdep.frequency.current";
+	else if(sysctlbyname("machdep.cpu.frequency.available", &freq, &freqsize,
+				NULL, 0) == 0)
+		p = "machdep.cpu.frequency.current";
 	else
 	{
 		error_set("%s: %s", applet.name, _("No support detected"));
@@ -125,6 +129,7 @@
 	gtk_box_pack_start(GTK_BOX(cpufreq->hbox), image, FALSE, TRUE, 0);
 	cpufreq->min = 0;
 	cpufreq->max = 0;
+	cpufreq->actual = 0;
 	cpufreq->step = 1;
 	cpufreq->name = p;
 	cpufreq->max = atoi(freq);
@@ -181,6 +186,9 @@
 		helper->error(NULL, error_get(NULL), 1);
 		return TRUE;
 	}
+	if (freq == cpufreq->actual)
+		return TRUE;
+	cpufreq->actual = freq;
 	snprintf(buf, sizeof(buf), "%4u", (unsigned int)freq);
 	gtk_label_set_text(GTK_LABEL(cpufreq->label), buf);
 # if GTK_CHECK_VERSION(2, 12, 0)
