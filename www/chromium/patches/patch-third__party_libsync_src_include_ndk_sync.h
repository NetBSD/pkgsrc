$NetBSD: patch-third__party_libsync_src_include_ndk_sync.h,v 1.1 2026/05/10 15:30:05 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/libsync/src/include/ndk/sync.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ third_party/libsync/src/include/ndk/sync.h
@@ -28,6 +28,7 @@
 
 #include <stdint.h>
 
+#if 0 
 #include <linux/sync_file.h>
 
 __BEGIN_DECLS
@@ -93,7 +94,7 @@ void sync_file_info_free(struct sync_fil
 #endif // __ANDROID_API__ >= __ANDROID_API_O__
 
 __END_DECLS
-
+#endif
 #endif /* ANDROID_SYNC_H */
 
 /** @} */
