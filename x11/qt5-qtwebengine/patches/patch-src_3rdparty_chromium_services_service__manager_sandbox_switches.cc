$NetBSD: patch-src_3rdparty_chromium_services_service__manager_sandbox_switches.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/services/service_manager/sandbox/switches.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/services/service_manager/sandbox/switches.cc
@@ -81,7 +81,7 @@ const char kGpuSandboxFailuresFatal[] = 
 // Disables the sandbox for all process types that are normally sandboxed.
 const char kNoSandbox[] = "no-sandbox";
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Instructs the zygote to launch without a sandbox. Processes forked from this
 // type of zygote will apply their own custom sandboxes later.
 const char kNoZygoteSandbox[] = "no-zygote-sandbox";
