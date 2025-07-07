$NetBSD: patch-sandbox_linux_services_init__process__reaper.cc,v 1.3 2025/07/07 09:23:36 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- sandbox/linux/services/init_process_reaper.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ sandbox/linux/services/init_process_reaper.cc
@@ -7,6 +7,7 @@
 #pragma allow_unsafe_libc_calls
 #endif
 
+#if 0
 #include "sandbox/linux/services/init_process_reaper.h"
 
 #include <signal.h>
@@ -105,3 +106,4 @@ bool CreateInitProcessReaper(base::OnceC
 }
 
 }  // namespace sandbox.
+#endif
