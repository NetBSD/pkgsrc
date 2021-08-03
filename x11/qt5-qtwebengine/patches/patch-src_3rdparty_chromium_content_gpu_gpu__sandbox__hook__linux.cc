$NetBSD: patch-src_3rdparty_chromium_content_gpu_gpu__sandbox__hook__linux.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/content/gpu/gpu_sandbox_hook_linux.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/content/gpu/gpu_sandbox_hook_linux.cc
@@ -97,8 +97,13 @@ static const char kLibV4lEncPluginPath[]
     "/usr/lib/libv4l/plugins/libv4l-encplugin.so";
 #endif
 
+#if defined(OS_LINUX)
 constexpr int dlopen_flag = RTLD_NOW | RTLD_GLOBAL | RTLD_NODELETE;
+#else
+constexpr int dlopen_flag = RTLD_NOW | RTLD_GLOBAL;
+#endif
 
+#if !defined(OS_BSD)
 void AddV4L2GpuWhitelist(
     std::vector<BrokerFilePermission>* permissions,
     const service_manager::SandboxSeccompBPF::Options& options) {
@@ -333,8 +338,10 @@ std::vector<BrokerFilePermission> FilePe
   AddStandardGpuWhiteList(&permissions);
   return permissions;
 }
+#endif
 
 void LoadArmGpuLibraries() {
+#if !defined(OS_BSD)
   // Preload the Mali library.
   if (UseChromecastSandboxWhitelist()) {
     for (const char* path : kWhitelistedChromecastPaths) {
@@ -349,6 +356,7 @@ void LoadArmGpuLibraries() {
     // Preload the Tegra V4L2 (video decode acceleration) library.
     dlopen(kLibTegraPath, dlopen_flag);
   }
+#endif
 }
 
 bool LoadAmdGpuLibraries() {
@@ -404,6 +412,7 @@ bool LoadLibrariesForGpu(
   return true;
 }
 
+#if !defined(OS_BSD)
 sandbox::syscall_broker::BrokerCommandSet CommandSetForGPU(
     const service_manager::SandboxLinux::Options& options) {
   sandbox::syscall_broker::BrokerCommandSet command_set;
@@ -425,13 +434,18 @@ bool BrokerProcessPreSandboxHook(
   service_manager::SetProcessTitleFromCommandLine(nullptr);
   return true;
 }
+#endif
 
 }  // namespace
 
 bool GpuProcessPreSandboxHook(service_manager::SandboxLinux::Options options) {
+#if defined(OS_BSD)
+  NOTIMPLEMENTED();
+#else
   service_manager::SandboxLinux::GetInstance()->StartBrokerProcess(
       CommandSetForGPU(options), FilePermissionsForGpu(options),
       base::BindOnce(BrokerProcessPreSandboxHook), options);
+#endif
 
   if (!LoadLibrariesForGpu(options))
     return false;
