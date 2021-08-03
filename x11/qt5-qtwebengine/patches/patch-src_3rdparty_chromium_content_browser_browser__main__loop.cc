$NetBSD: patch-src_3rdparty_chromium_content_browser_browser__main__loop.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/content/browser/browser_main_loop.cc.orig	2020-07-15 18:56:47.000000000 +0000
+++ src/3rdparty/chromium/content/browser/browser_main_loop.cc
@@ -240,6 +240,12 @@
 #include "mojo/public/cpp/bindings/lib/test_random_mojo_delays.h"
 #endif
 
+#if defined(OS_BSD)
+#include "content/browser/sandbox_host_linux.h"
+#include "content/public/common/common_sandbox_support_linux.h"
+#include "services/service_manager/sandbox/sandbox.h"
+#endif
+
 // One of the linux specific headers defines this as a macro.
 #ifdef DestroyAll
 #undef DestroyAll
@@ -611,7 +617,7 @@ int BrowserMainLoop::EarlyInitialization
 #endif  // !defined(OS_MACOSX)
 
 #if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_ANDROID)
+    defined(OS_ANDROID) || defined(OS_BSD)
   // We use quite a few file descriptors for our IPC as well as disk the disk
   // cache,and the default limit on the Mac is low (256), so bump it up.
 
