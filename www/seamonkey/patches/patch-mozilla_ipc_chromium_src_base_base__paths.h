$NetBSD: patch-mozilla_ipc_chromium_src_base_base__paths.h,v 1.2 2012/03/19 10:35:59 ryoon Exp $

--- mozilla/ipc/chromium/src/base/base_paths.h.orig	2012-03-13 05:32:38.000000000 +0000
+++ mozilla/ipc/chromium/src/base/base_paths.h
@@ -13,7 +13,7 @@
 #include "base/base_paths_win.h"
 #elif defined(OS_MACOSX)
 #include "base/base_paths_mac.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "base/base_paths_linux.h"
 #endif
 #include "base/path_service.h"
