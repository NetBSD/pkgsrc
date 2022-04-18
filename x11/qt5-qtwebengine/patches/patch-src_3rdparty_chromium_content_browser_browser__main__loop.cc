$NetBSD: patch-src_3rdparty_chromium_content_browser_browser__main__loop.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/content/browser/browser_main_loop.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/content/browser/browser_main_loop.cc
@@ -246,6 +246,12 @@
 #include "mojo/public/cpp/bindings/lib/test_random_mojo_delays.h"
 #endif
 
+#if defined(OS_BSD)
+#include "content/browser/sandbox_host_linux.h"
+#include "content/public/common/common_sandbox_support_linux.h"
+#include "sandbox/policy/sandbox.h"
+#endif
+
 // One of the linux specific headers defines this as a macro.
 #ifdef DestroyAll
 #undef DestroyAll
@@ -629,7 +635,7 @@ int BrowserMainLoop::EarlyInitialization
 #endif  // !defined(OS_MAC)
 
 #if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_ANDROID)
+    defined(OS_ANDROID) || defined(OS_BSD)
   // We use quite a few file descriptors for our IPC as well as disk the disk
   // cache,and the default limit on the Mac is low (256), so bump it up.
 
