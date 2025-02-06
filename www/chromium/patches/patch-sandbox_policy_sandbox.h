$NetBSD: patch-sandbox_policy_sandbox.h,v 1.1 2025/02/06 09:58:19 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- sandbox/policy/sandbox.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ sandbox/policy/sandbox.h
@@ -12,6 +12,14 @@
 #include "sandbox/policy/linux/sandbox_linux.h"
 #endif
 
+#if BUILDFLAG(IS_OPENBSD)
+#include "sandbox/policy/openbsd/sandbox_openbsd.h"
+#elif BUILDFLAG(IS_NETBSD)
+#include "sandbox/policy/netbsd/sandbox_netbsd.h"
+#elif BUILDFLAG(IS_FREEBSD)
+#include "sandbox/policy/freebsd/sandbox_freebsd.h"
+#endif
+
 namespace sandbox {
 namespace mojom {
 enum class Sandbox;
@@ -32,7 +40,7 @@ namespace policy {
 
 class SANDBOX_POLICY_EXPORT Sandbox {
  public:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static bool Initialize(sandbox::mojom::Sandbox sandbox_type,
                          SandboxLinux::PreSandboxHook hook,
                          const SandboxLinux::Options& options);
