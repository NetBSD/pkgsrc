$NetBSD: patch-sandbox_policy_sandbox.cc,v 1.20 2026/06/01 10:09:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- sandbox/policy/sandbox.cc.orig	2026-05-26 20:39:02.000000000 +0000
+++ sandbox/policy/sandbox.cc
@@ -20,6 +20,10 @@
 #include "sandbox/policy/linux/sandbox_linux.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#endif  // BUILDFLAG(IS_BSD)
+
 #if BUILDFLAG(IS_MAC)
 #include "sandbox/mac/seatbelt.h"
 #endif  // BUILDFLAG(IS_MAC)
@@ -36,7 +40,7 @@
 namespace sandbox {
 namespace policy {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool Sandbox::Initialize(sandbox::mojom::Sandbox sandbox_type,
                          SandboxLinux::PreSandboxHook hook,
                          const SandboxLinux::Options& options) {
