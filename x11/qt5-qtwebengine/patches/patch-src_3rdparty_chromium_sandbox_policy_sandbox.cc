$NetBSD: patch-src_3rdparty_chromium_sandbox_policy_sandbox.cc,v 1.1 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/sandbox/policy/sandbox.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/sandbox/policy/sandbox.cc
@@ -16,6 +16,14 @@
 #include "sandbox/policy/linux/sandbox_linux.h"
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
 
+#if defined(OS_OPENBSD)
+#include "sandbox/policy/openbsd/sandbox_openbsd.h"
+#endif
+
+#if defined(OS_NETBSD)
+#include "sandbox/policy/netbsd/sandbox_netbsd.h"
+#endif
+
 #if defined(OS_MAC)
 #include "sandbox/mac/seatbelt.h"
 #include "sandbox/policy/mac/sandbox_mac.h"
@@ -30,7 +38,7 @@
 namespace sandbox {
 namespace policy {
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 bool Sandbox::Initialize(SandboxType sandbox_type,
                          SandboxLinux::PreSandboxHook hook,
                          const SandboxLinux::Options& options) {
