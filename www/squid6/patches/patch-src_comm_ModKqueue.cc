$NetBSD: patch-src_comm_ModKqueue.cc,v 1.1 2023/09/13 07:36:45 taca Exp $

* Fix kqueue(2) for NetBSD.

--- src/comm/ModKqueue.cc.orig	2019-11-05 19:14:40.000000000 +0000
+++ src/comm/ModKqueue.cc
@@ -43,6 +43,9 @@
 #if HAVE_SYS_EVENT_H
 #include <sys/event.h>
 #endif
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
 
 #define KE_LENGTH        128
 
@@ -109,7 +112,11 @@ kq_update_events(int fd, short filter, P
             kep_flags = EV_DELETE;
         }
 
+#if defined(__NetBSD__) && (__NetBSD_Version__ - 0 < 999001500)
+        EV_SET(kep, (uintptr_t) fd, filter, kep_flags, 0, 0, (intptr_t)0);
+#else
         EV_SET(kep, (uintptr_t) fd, filter, kep_flags, 0, 0, 0);
+#endif
 
         /* Check if we've used the last one. If we have then submit them all */
         if (kqoff == kqmax - 1) {
