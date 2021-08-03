$NetBSD: patch-src_3rdparty_chromium_base_path__service__unittest.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/path_service_unittest.cc.orig	2020-06-25 09:31:18.000000000 +0000
+++ src/3rdparty/chromium/base/path_service_unittest.cc
@@ -37,7 +37,7 @@ bool ReturnsValidPath(int dir_type) {
   if (dir_type == DIR_CACHE)
     check_path_exists = false;
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On the linux try-bots: a path is returned (e.g. /home/chrome-bot/Desktop),
   // but it doesn't exist.
   if (dir_type == DIR_USER_DESKTOP)
