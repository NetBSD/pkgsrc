$NetBSD: patch-sandbox_policy_switches.h,v 1.14 2026/01/19 16:14:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- sandbox/policy/switches.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ sandbox/policy/switches.h
@@ -24,7 +24,8 @@ SANDBOX_POLICY_EXPORT extern const char 
 SANDBOX_POLICY_EXPORT extern const char kGpuSandboxAllowSysVShm[];
 SANDBOX_POLICY_EXPORT extern const char kGpuSandboxFailuresFatal[];
 SANDBOX_POLICY_EXPORT extern const char kNoSandbox[];
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+SANDBOX_POLICY_EXPORT extern const char kDisableUnveil[];
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 SANDBOX_POLICY_EXPORT extern const char kNoZygoteSandbox[];
 #endif
 #if BUILDFLAG(IS_WIN)
