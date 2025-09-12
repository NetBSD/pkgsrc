$NetBSD: patch-third__party_libsync_src_include_sync_sync.h,v 1.7 2025/09/12 16:02:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/libsync/src/include/sync/sync.h.orig	2025-09-08 23:21:33.000000000 +0000
+++ third_party/libsync/src/include/sync/sync.h
@@ -22,7 +22,9 @@
 #include <sys/cdefs.h>
 #include <stdint.h>
 
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__)
 #include <linux/types.h>
+#endif
 
 __BEGIN_DECLS
 
