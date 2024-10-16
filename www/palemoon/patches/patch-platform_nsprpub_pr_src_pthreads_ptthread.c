$NetBSD: patch-platform_nsprpub_pr_src_pthreads_ptthread.c,v 1.1.2.2 2024/10/16 09:01:50 bsiegert Exp $

pthread_t may be 64-bit, avoid integer truncation.
https://bugzilla.mozilla.org/show_bug.cgi?id=1718835

--- platform/nsprpub/pr/src/pthreads/ptthread.c.orig	2024-09-05 08:13:09.000000000 +0000
+++ platform/nsprpub/pr/src/pthreads/ptthread.c
@@ -1183,9 +1183,9 @@ PR_IMPLEMENT(void) PR_ProcessExit(PRIntn
     _exit(status);
 }
 
-PR_IMPLEMENT(PRUint32) PR_GetThreadID(PRThread *thred)
+PR_IMPLEMENT(pthread_t) PR_GetThreadID(PRThread *thred)
 {
-    return (PRUint32)thred->id;  /* and I don't know what they will do with it */
+    return (pthread_t)thred->id;  /* and I don't know what they will do with it */
 }
 
 /*
