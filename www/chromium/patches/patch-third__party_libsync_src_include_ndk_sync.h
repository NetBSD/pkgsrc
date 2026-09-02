$NetBSD: patch-third__party_libsync_src_include_ndk_sync.h,v 1.7 2026/09/02 13:13:37 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/libsync/src/include/ndk/sync.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ third_party/libsync/src/include/ndk/sync.h
@@ -29,6 +29,7 @@
 #include <stdint.h>
 #include <sys/cdefs.h>
 
+#if 0 
 #include <linux/sync_file.h>
 
 __BEGIN_DECLS
@@ -100,7 +101,7 @@ static inline struct sync_fence_info* sy
 void sync_file_info_free(struct sync_file_info* info) __INTRODUCED_IN(26);
 
 __END_DECLS
-
+#endif
 #endif /* ANDROID_SYNC_H */
 
 /** @} */
