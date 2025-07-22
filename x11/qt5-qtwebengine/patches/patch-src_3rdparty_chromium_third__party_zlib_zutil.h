$NetBSD: patch-src_3rdparty_chromium_third__party_zlib_zutil.h,v 1.1 2025/07/22 10:16:36 adam Exp $

Fix build with Xcode 16.3.

--- src/3rdparty/chromium/third_party/zlib/zutil.h.orig	2025-07-22 06:13:38.276005065 +0000
+++ src/3rdparty/chromium/third_party/zlib/zutil.h
@@ -152,7 +152,7 @@ extern z_const char * const z_errmsg[10]
 #  endif
 #endif
 
-#if defined(MACOS) || defined(TARGET_OS_MAC)
+#if defined(MACOS)
 #  define OS_CODE  7
 #  ifndef Z_SOLO
 #    if defined(__MWERKS__) && __dest_os != __be_os && __dest_os != __win32_os
