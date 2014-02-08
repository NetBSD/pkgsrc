$NetBSD: patch-ipc_chromium_src_base_base__paths.h,v 1.2 2014/02/08 09:36:00 ryoon Exp $

--- ipc/chromium/src/base/base_paths.h.orig	2014-01-28 04:03:44.000000000 +0000
+++ ipc/chromium/src/base/base_paths.h
@@ -13,7 +13,7 @@
 #include "base/base_paths_win.h"
 #elif defined(OS_MACOSX)
 #include "base/base_paths_mac.h"
-#elif defined(OS_LINUX) || defined(OS_BSD)
+#elif defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
 #include "base/base_paths_linux.h"
 #endif
 #include "base/path_service.h"
