$NetBSD: patch-src_3rdparty_chromium_content_gpu_gpu__main.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/content/gpu/gpu_main.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/content/gpu/gpu_main.cc
@@ -84,7 +84,7 @@
 #include "ui/gfx/x/x11_switches.h"                       // nogncheck
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "content/gpu/gpu_sandbox_hook_linux.h"
 #include "content/public/common/sandbox_init.h"
 #include "services/service_manager/sandbox/linux/sandbox_linux.h"
@@ -109,7 +109,7 @@ namespace content {
 
 namespace {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 bool StartSandboxLinux(gpu::GpuWatchdogThread*,
                        const gpu::GPUInfo*,
                        const gpu::GpuPreferences&);
@@ -162,7 +162,7 @@ class ContentSandboxHelper : public gpu:
   bool EnsureSandboxInitialized(gpu::GpuWatchdogThread* watchdog_thread,
                                 const gpu::GPUInfo* gpu_info,
                                 const gpu::GpuPreferences& gpu_prefs) override {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     return StartSandboxLinux(watchdog_thread, gpu_info, gpu_prefs);
 #elif defined(OS_WIN)
     return StartSandboxWindows(sandbox_info_);
@@ -290,7 +290,7 @@ int GpuMain(const MainFunctionParams& pa
     main_thread_task_executor =
         std::make_unique<base::SingleThreadTaskExecutor>(
             gpu_preferences.message_pump_type);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #error "Unsupported Linux platform."
 #elif defined(OS_MACOSX)
     // Cross-process CoreAnimation requires a CFRunLoop to function at all, and
@@ -436,7 +436,7 @@ int GpuMain(const MainFunctionParams& pa
 
 namespace {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 bool StartSandboxLinux(gpu::GpuWatchdogThread* watchdog_thread,
                        const gpu::GPUInfo* gpu_info,
                        const gpu::GpuPreferences& gpu_prefs) {
