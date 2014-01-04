$NetBSD: patch-logging.c,v 1.3 2014/01/04 13:56:01 rodent Exp $

--- core/logging.c.orig	2013-08-23 12:51:18.000000000 +0000
+++ core/logging.c
@@ -306,7 +306,7 @@ void uwsgi_setup_log_master(void) {
 			int is_id = 1;
 			int i;
 			for (i = 0; i < (space - name); i++) {
-				if (!isalnum(name[i])) {
+				if (!isalnum((int) name[i])) {
 					is_id = 0;
 					break;
 				}
@@ -695,8 +695,13 @@ void get_memusage(uint64_t * rss, uint64
 		struct kinfo_proc *kproc;
 		kproc = kvm_getprocs(kv, KERN_PROC_PID, uwsgi.mypid, &cnt);
 		if (kproc && cnt > 0) {
+#if defined(__FreeBSD__)
 			*vsz = kproc->ki_size;
 			*rss = kproc->ki_rssize * uwsgi.page_size;
+#elif defined(__DragonFly__)
+			*vsz = kproc->kp_vm_map_size;
+			*rss = kproc->kp_vm_rssize * uwsgi.page_size;
+#endif
 		}
 #elif defined(UWSGI_NEW_OPENBSD)
 		struct kinfo_proc *kproc;
