$NetBSD: patch-sandbox_policy_sandbox.cc,v 1.24 2026/08/09 06:31:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- sandbox/policy/sandbox.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ sandbox/policy/sandbox.cc
@@ -22,6 +22,10 @@
 #include "sandbox/policy/linux/sandbox_linux.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#endif  // BUILDFLAG(IS_BSD)
+
 #if BUILDFLAG(IS_MAC)
 #include "sandbox/mac/seatbelt.h"
 #endif  // BUILDFLAG(IS_MAC)
@@ -38,7 +42,7 @@
 namespace sandbox {
 namespace policy {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool Sandbox::Initialize(sandbox::mojom::Sandbox sandbox_type,
                          SandboxLinux::PreSandboxHook hook,
                          const SandboxLinux::Options& options) {
