$NetBSD: patch-src_3rdparty_chromium_third__party_libsync_src_include_sync_sync.h,v 1.1 2025/12/21 09:38:42 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/libsync/src/include/sync/sync.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/third_party/libsync/src/include/sync/sync.h
@@ -22,7 +22,9 @@
 #include <sys/cdefs.h>
 #include <stdint.h>
 
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__)
 #include <linux/types.h>
+#endif
 
 __BEGIN_DECLS
 
