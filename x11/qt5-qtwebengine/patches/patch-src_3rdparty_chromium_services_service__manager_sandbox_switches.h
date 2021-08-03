$NetBSD: patch-src_3rdparty_chromium_services_service__manager_sandbox_switches.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/services/service_manager/sandbox/switches.h.orig	2020-07-15 18:56:47.000000000 +0000
+++ src/3rdparty/chromium/services/service_manager/sandbox/switches.h
@@ -55,7 +55,7 @@ SERVICE_MANAGER_SANDBOX_EXPORT extern co
 SERVICE_MANAGER_SANDBOX_EXPORT extern const char kGpuSandboxAllowSysVShm[];
 SERVICE_MANAGER_SANDBOX_EXPORT extern const char kGpuSandboxFailuresFatal[];
 SERVICE_MANAGER_SANDBOX_EXPORT extern const char kNoSandbox[];
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 SERVICE_MANAGER_SANDBOX_EXPORT extern const char kNoZygoteSandbox[];
 #endif
 #if defined(OS_WIN)
