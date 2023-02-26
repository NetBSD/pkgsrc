$NetBSD: patch-core_logging.c,v 1.6 2023/02/26 00:52:49 joerg Exp $

Fix build for NetBSD.

--- core/logging.c.orig	2022-10-24 10:21:58.000000000 +0000
+++ core/logging.c
@@ -1,10 +1,12 @@
 #ifndef __DragonFly__
 #include "uwsgi.h"
 #endif
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__OpenBSD__)
 #include <sys/user.h>
 #include <sys/sysctl.h>
 #include <kvm.h>
+#elif defined(__NetBSD__)
+#include <sys/sysctl.h>
 #elif defined(__sun__)
 /* Terrible Hack !!! */
 #ifndef _LP64
@@ -791,13 +793,30 @@ void get_memusage(uint64_t * rss, uint64
 		*rss = t_info.resident_size;
 		*vsz = t_info.virtual_size;
 	}
-#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__OpenBSD__)
+#elif defined(__NetBSD__)
+	struct kinfo_proc2 kproc;
+	int mib[6];
+	size_t size;
+
+	mib[0] = CTL_KERN;
+	mib[1] = KERN_PROC2;
+	mib[2] = KERN_PROC_PID;
+	mib[3] = uwsgi.mypid;
+	mib[4] = sizeof(kproc);
+	mib[5] = 1;
+	if (sysctl(mib, 6, &kproc, &size, NULL, 0) == -1) {
+		uwsgi_log("warning: failed to read process statistics\n");
+		return;
+	}
+	*vsz = kproc.p_vm_vsize * uwsgi.page_size;
+	*rss = kproc.p_vm_rssize * uwsgi.page_size;
+#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__OpenBSD__)
 	kvm_t *kv;
 	int cnt;
 
 #if defined(__FreeBSD__)
 	kv = kvm_open(NULL, "/dev/null", NULL, O_RDONLY, NULL);
-#elif defined(__NetBSD__) || defined(__OpenBSD__)
+#elif defined(__OpenBSD__)
 	kv = kvm_open(NULL, NULL, NULL, KVM_NO_FILES, NULL);
 #else
 	kv = kvm_open(NULL, NULL, NULL, O_RDONLY, NULL);
@@ -823,7 +842,7 @@ void get_memusage(uint64_t * rss, uint64
 			*vsz = (kproc->p_vm_dsize + kproc->p_vm_ssize + kproc->p_vm_tsize) * uwsgi.page_size;
 			*rss = kproc->p_vm_rssize * uwsgi.page_size;
 		}
-#elif defined(__NetBSD__) || defined(__OpenBSD__)
+#elif defined(__OpenBSD__)
 		struct kinfo_proc2 *kproc2;
 
 		kproc2 = kvm_getproc2(kv, KERN_PROC_PID, uwsgi.mypid, sizeof(struct kinfo_proc2), &cnt);
