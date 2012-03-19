$NetBSD: patch-ksysguard_ksysguardd_NetBSD_CPU.c,v 1.1 2012/03/19 19:44:03 markd Exp $

--- ksysguard/ksysguardd/NetBSD/CPU.c.orig	2008-01-05 12:55:45.000000000 +1300
+++ ksysguard/ksysguardd/NetBSD/CPU.c
@@ -49,12 +49,16 @@ initCpuInfo(struct SensorModul* sm)
 	registerMonitor("cpu/system/nice", "integer", printCPUNice, printCPUNiceInfo, sm);
 	registerMonitor("cpu/system/sys", "integer", printCPUSys, printCPUSysInfo, sm);
 	registerMonitor("cpu/system/idle", "integer", printCPUIdle, printCPUIdleInfo, sm);
+	registerMonitor("cpu/system/intr", "integer", printCPUIntr, printCPUIntrInfo, sm);
+	/* linux compat */
+	registerMonitor("cpu/system/wait", "integer", printCPUWait, printCPUWaitInfo, sm);
 	
 	/* Monitor names changed from kde3 => kde4. Remain compatible with legacy requests when possible. */
 	registerLegacyMonitor("cpu/user", "integer", printCPUUser, printCPUUserInfo, sm);
 	registerLegacyMonitor("cpu/nice", "integer", printCPUNice, printCPUNiceInfo, sm);
 	registerLegacyMonitor("cpu/sys", "integer", printCPUSys, printCPUSysInfo, sm);
 	registerLegacyMonitor("cpu/idle", "integer", printCPUIdle, printCPUIdleInfo, sm);
+	registerMonitor("cpu/wait", "integer", printCPUWait, printCPUWaitInfo, sm);
 	
 	updateCpuInfo();
 }
@@ -66,12 +70,15 @@ exitCpuInfo(void)
 	removeMonitor("cpu/system/nice");
 	removeMonitor("cpu/system/sys");
 	removeMonitor("cpu/system/idle");
+	removeMonitor("cpu/system/intr");
+	removeMonitor("cpu/system/wait");
 
 	/* These were registered as legacy monitors */
 	removeMonitor("cpu/user");
 	removeMonitor("cpu/nice");
 	removeMonitor("cpu/sys");
 	removeMonitor("cpu/idle");
+	removeMonitor("cpu/wait");
 }
 
 int
@@ -136,6 +143,29 @@ printCPUIdleInfo(const char* cmd)
 	fprintf(CurrentClient, "CPU Idle Load\t0\t100\t%%\n");
 }
 
+void
+printCPUIntr(const char* cmd)
+{
+	fprintf(CurrentClient, "%d\n", cpu_states[CP_INTR]/10);
+}
+
+void
+printCPUIntrInfo(const char* cmd)
+{
+	fprintf(CurrentClient, "CPU Interrupt Load\t0\t100\t%%\n");
+}
+
+void
+printCPUWait(const char* cmd)
+{
+	fprintf(CurrentClient, "0\n");
+}
+
+void
+printCPUWaitInfo(const char* cmd)
+{
+	fprintf(CurrentClient, "CPU Wait Load\t0\t100\t%%\n");
+}
 
 /* The part ripped from top... */
 /*
