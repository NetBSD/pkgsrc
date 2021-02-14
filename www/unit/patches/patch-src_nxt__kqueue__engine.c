$NetBSD: patch-src_nxt__kqueue__engine.c,v 1.1 2021/02/14 11:56:57 otis Exp $

Use correct types on NetBSD-CURRENT.

This patch is going to be reviewed by the vendor.

--- src/nxt_kqueue_engine.c.orig	2021-02-04 15:22:33.000000000 +0000
+++ src/nxt_kqueue_engine.c
@@ -39,8 +39,10 @@
 #endif
 
 
-#if (NXT_NETBSD)
-/* NetBSD defines the kevent.udata field as intptr_t. */
+#if (NXT_NETBSD) && (defined(__NetBSD__) && __NetBSD_Version__ < 999001500)
+/* NetBSD up to 9.99.15 defines the kevent.udata field as intptr_t.
+ * NetBSD 9.99.16 onwards defines the kevent.udata field as void*
+ */
 
 #define nxt_kevent_set_udata(udata)  (intptr_t) (udata)
 #define nxt_kevent_get_udata(udata)  (void *) (udata)
