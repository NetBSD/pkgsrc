$NetBSD: patch-logging.c,v 1.1 2012/05/15 12:56:38 marino Exp $

--- logging.c.orig	2011-09-11 05:50:42.000000000 +0000
+++ logging.c
@@ -179,7 +179,7 @@ void get_memusage() {
 	kv = kvm_open(NULL, NULL, NULL, O_RDONLY, NULL);
 #endif
 	if (kv) {
-#if defined(__FreeBSD__) || defined(__DragonFly__)
+#if defined(__FreeBSD__)
 
 		struct kinfo_proc *kproc;
 		kproc = kvm_getprocs(kv, KERN_PROC_PID, uwsgi.mypid, &cnt);
@@ -187,6 +187,13 @@ void get_memusage() {
 			uwsgi.workers[uwsgi.mywid].vsz_size = kproc->ki_size;
 			uwsgi.workers[uwsgi.mywid].rss_size = kproc->ki_rssize * uwsgi.page_size;
 		}
+#elif defined(__DragonFly__)
+		struct kinfo_proc *kproc;
+		kproc = kvm_getprocs(kv, KERN_PROC_PID, uwsgi.mypid, &cnt);
+		if (kproc && cnt > 0) {
+			uwsgi.workers[uwsgi.mywid].vsz_size = kproc->kp_vm_map_size;
+			uwsgi.workers[uwsgi.mywid].rss_size = kproc->kp_vm_rssize * uwsgi.page_size;
+		}
 #elif defined(__NetBSD__) || defined(__OpenBSD__)
 		struct kinfo_proc2 *kproc2;
 
