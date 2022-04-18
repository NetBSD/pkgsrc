$NetBSD: patch-src_3rdparty_chromium_sandbox_policy_switches.cc,v 1.1 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/sandbox/policy/switches.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/sandbox/policy/switches.cc
@@ -81,7 +81,7 @@ const char kGpuSandboxFailuresFatal[] = 
 // Meant to be used as a browser-level switch for testing purposes only.
 const char kNoSandbox[] = "no-sandbox";
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // Instructs the zygote to launch without a sandbox. Processes forked from this
 // type of zygote will apply their own custom sandboxes later.
 const char kNoZygoteSandbox[] = "no-zygote-sandbox";
