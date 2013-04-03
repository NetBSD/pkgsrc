$NetBSD: patch-ksysguard_ksysguard_FreeBSD_ProcessList.c,v 1.2 2013/04/03 10:51:50 markd Exp $

--- ksysguard/ksysguardd/FreeBSD/ProcessList.c.orig	2013-03-01 06:32:24.000000000 +0000
+++ ksysguard/ksysguardd/FreeBSD/ProcessList.c
@@ -54,6 +54,24 @@
 
 #define MONITORBUF 20
 
+#if defined(__DragonFly__)
+#include <kvm.h>
+#include <limits.h>
+#define ki_comm    kp_comm
+#define ki_nice    kp_nice
+#define ki_pid     kp_pid
+#define ki_pgid    kp_pgid
+#define ki_ppid    kp_ppid
+#define ki_ruid    kp_ruid
+#define ki_runtime kp_lwp.kl_pctcpu
+#define ki_rssize  kp_vm_rssize
+#define ki_size    kp_vm_map_size
+#define ki_stat    kp_stat
+#define ki_start   kp_start
+#define ki_uid     kp_uid
+#define KERN_PROC_PROC KERN_PROC_ALL
+#endif
+
 static struct kinfo_proc proc_buf[PROCBUF], prev_list[PROCBUF];
 static int nproc, prev_nproc, sorted_proc[PROCBUF], prev_sorted[PROCBUF];
 
@@ -230,7 +248,11 @@ void printProcessList(const char* cmd)
                 *arg_fix = '*';
         }
 
+#if defined(__DragonFly__)
+        if (args[0] == '\0' && (ps->kp_flags & P_SYSTEM)) {
+#else
         if (args[0] == '\0' && (ps->ki_flag & P_SYSTEM || ps->ki_args == NULL)) {
+#endif
             int cpy;
             cpy = strlcpy(buf3 + 1, ps->ki_comm, NAMEBUF - 1);
             if (cpy > NAMEBUF - 2)
@@ -246,6 +268,17 @@ void printProcessList(const char* cmd)
             name = "????";
 
         switch (ps->ki_stat) {
+#if defined(__DragonFly__)
+            case SACTIVE:
+                if (smpmode)
+                    state = cpunames[ps->kp_lwp.kl_cpuid];
+                else
+                    state = statuses[2];
+                break;
+            case SIDL:
+            case SSTOP:
+            case SZOMB:
+#else
             case SRUN:
                 if (smpmode && ps->ki_oncpu != 0xff)
                     state = cpunames[ps->ki_oncpu];
@@ -269,6 +302,7 @@ void printProcessList(const char* cmd)
             case SSTOP:
             case SZOMB:
             case SWAIT:
+#endif
                 state = statuses[(int)ps->ki_stat];
                 break;
 
@@ -300,10 +334,15 @@ void printProcessList(const char* cmd)
             ++prev_proc;
         }
 
+#if defined(__DragonFly__)
+	/* XXX */
+	load = 0;
+#else
         if (last_ps != NULL)
             load = (ps->ki_runtime - last_ps->ki_runtime) / 1000000.0 / scale;
         else
             load = ps->ki_runtime / 1000000.0 / scale;
+#endif
 
         if (!ps->ki_pid)
             /* XXX: TODO: add support for displaying kernel process */
