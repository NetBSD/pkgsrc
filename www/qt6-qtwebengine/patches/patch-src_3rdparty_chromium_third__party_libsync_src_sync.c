$NetBSD: patch-src_3rdparty_chromium_third__party_libsync_src_sync.c,v 1.1 2025/12/21 09:38:42 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/libsync/src/sync.c.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/third_party/libsync/src/sync.c
@@ -17,8 +17,8 @@
  */
 
 #include <fcntl.h>
-#include <malloc.h>
 #include <stdint.h>
+#include <stdlib.h>
 #include <string.h>
 #include <errno.h>
 #include <poll.h>
@@ -29,6 +29,12 @@
 
 #include <sync/sync.h>
 
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
+typedef __uint8_t __u8;
+typedef __uint32_t __u32;
+typedef __int32_t __s32;
+#define ETIME ETIMEDOUT
+#endif
 
 struct sw_sync_create_fence_data {
   __u32 value;
