$NetBSD: patch-mozilla_ipc_chromium_src_base_base__paths.h,v 1.8 2013/08/11 03:18:46 ryoon Exp $

--- mozilla/ipc/chromium/src/base/base_paths.h.orig	2013-08-04 03:05:29.000000000 +0000
+++ mozilla/ipc/chromium/src/base/base_paths.h
@@ -13,7 +13,7 @@
 #include "base/base_paths_win.h"
 #elif defined(OS_MACOSX)
 #include "base/base_paths_mac.h"
-#elif defined(OS_LINUX) || defined(OS_BSD)
+#elif defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
 #include "base/base_paths_linux.h"
 #endif
 #include "base/path_service.h"
