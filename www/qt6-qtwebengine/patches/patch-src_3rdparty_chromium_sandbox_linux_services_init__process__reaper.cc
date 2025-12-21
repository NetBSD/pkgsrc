$NetBSD: patch-src_3rdparty_chromium_sandbox_linux_services_init__process__reaper.cc,v 1.1 2025/12/21 09:38:35 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/sandbox/linux/services/init_process_reaper.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/sandbox/linux/services/init_process_reaper.cc
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
