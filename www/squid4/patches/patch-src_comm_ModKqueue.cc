$NetBSD: patch-src_comm_ModKqueue.cc,v 1.1 2020/01/04 10:57:18 taca Exp $

* Fix kqueue(2) for NetBSD.

--- src/comm/ModKqueue.cc.orig	2019-07-09 19:05:20.000000000 +0000
+++ src/comm/ModKqueue.cc
@@ -109,7 +109,11 @@ kq_update_events(int fd, short filter, P
             kep_flags = EV_DELETE;
         }
 
+#ifdef __NetBSD__
+        EV_SET(kep, (uintptr_t) fd, filter, kep_flags, 0, 0, (intptr_t)0);
+#else
         EV_SET(kep, (uintptr_t) fd, filter, kep_flags, 0, 0, 0);
+#endif
 
         /* Check if we've used the last one. If we have then submit them all */
         if (kqoff == kqmax - 1) {
