$NetBSD: patch-logging.c,v 1.2 2012/07/12 16:21:53 roy Exp $

--- logging.c.orig	2012-05-14 06:58:20.000000000 +0100
+++ logging.c	2012-07-06 15:31:08.000000000 +0100
@@ -263,7 +263,7 @@
 	kv = kvm_open(NULL, NULL, NULL, O_RDONLY, NULL);
 #endif
 	if (kv) {
-#if defined(__FreeBSD__) || defined(__DragonFly__)
+#if defined(__FreeBSD__)
 
 		struct kinfo_proc *kproc;
 		kproc = kvm_getprocs(kv, KERN_PROC_PID, uwsgi.mypid, &cnt);
@@ -271,6 +271,13 @@
 			*vsz = kproc->ki_size;
 			*rss = kproc->ki_rssize * uwsgi.page_size;
 		}
+#elif defined(__DragonFly__)
+		struct kinfo_proc *kproc;
+		kproc = kvm_getprocs(kv, KERN_PROC_PID, uwsgi.mypid, &cnt);
+		if (kproc && cnt > 0) {
+			*vsz = kproc->kp_vm_map_size;
+			*rss = kproc->kp_vm_rssize * uwsgi.page_size;
+		}
 #elif defined(UWSGI_NEW_OPENBSD)
 		struct kinfo_proc *kproc; 
 		kproc = kvm_getprocs(kv, KERN_PROC_PID, uwsgi.mypid, sizeof(struct kinfo_proc), &cnt);
