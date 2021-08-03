$NetBSD: patch-src_3rdparty_chromium_services_service__manager_sandbox_sandbox.h,v 1.1 2021/08/03 21:04:35 markd Exp $

Index: src/3rdparty/chromium/services/service_manager/sandbox/sandbox.h
--- src/3rdparty/chromium/services/service_manager/sandbox/sandbox.h.orig
+++ src/3rdparty/chromium/services/service_manager/sandbox/sandbox.h
@@ -13,6 +13,14 @@
 #include "services/service_manager/sandbox/linux/sandbox_linux.h"
 #endif
 
+#if defined(OS_OPENBSD)
+#include "services/service_manager/sandbox/openbsd/sandbox_openbsd.h"
+#endif
+
+#if defined(OS_NETBSD)
+#include "services/service_manager/sandbox/netbsd/sandbox_netbsd.h"
+#endif
+
 #if defined(OS_MACOSX)
 #include "base/callback.h"
 #endif  // defined(OS_MACOSX)
@@ -34,7 +38,7 @@ namespace service_manager {
 
 class SERVICE_MANAGER_SANDBOX_EXPORT Sandbox {
  public:
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   static bool Initialize(SandboxType sandbox_type,
                          SandboxLinux::PreSandboxHook hook,
                          const SandboxLinux::Options& options);
