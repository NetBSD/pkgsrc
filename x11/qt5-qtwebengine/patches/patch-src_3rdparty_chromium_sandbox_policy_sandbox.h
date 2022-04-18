$NetBSD: patch-src_3rdparty_chromium_sandbox_policy_sandbox.h,v 1.1 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/sandbox/policy/sandbox.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/sandbox/policy/sandbox.h
@@ -13,6 +13,14 @@
 #include "sandbox/policy/linux/sandbox_linux.h"
 #endif
 
+#if defined(OS_OPENBSD)
+#include "sandbox/policy/openbsd/sandbox_openbsd.h"
+#endif
+
+#if defined(OS_NETBSD)
+#include "sandbox/policy/netbsd/sandbox_netbsd.h"
+#endif
+
 #if defined(OS_MAC)
 #include "base/callback.h"
 #endif  // defined(OS_MAC)
@@ -34,7 +42,7 @@ namespace policy {
 
 class SANDBOX_POLICY_EXPORT Sandbox {
  public:
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   static bool Initialize(SandboxType sandbox_type,
                          SandboxLinux::PreSandboxHook hook,
                          const SandboxLinux::Options& options);
