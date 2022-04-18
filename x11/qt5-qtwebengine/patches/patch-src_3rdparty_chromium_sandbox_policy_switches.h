$NetBSD: patch-src_3rdparty_chromium_sandbox_policy_switches.h,v 1.1 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/sandbox/policy/switches.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/sandbox/policy/switches.h
@@ -53,7 +53,7 @@ SANDBOX_POLICY_EXPORT extern const char 
 SANDBOX_POLICY_EXPORT extern const char kGpuSandboxAllowSysVShm[];
 SANDBOX_POLICY_EXPORT extern const char kGpuSandboxFailuresFatal[];
 SANDBOX_POLICY_EXPORT extern const char kNoSandbox[];
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 SANDBOX_POLICY_EXPORT extern const char kNoZygoteSandbox[];
 #endif
 #if defined(OS_WIN)
