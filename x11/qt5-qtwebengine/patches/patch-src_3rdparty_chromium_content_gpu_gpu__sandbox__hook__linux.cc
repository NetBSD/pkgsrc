$NetBSD: patch-src_3rdparty_chromium_content_gpu_gpu__sandbox__hook__linux.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/content/gpu/gpu_sandbox_hook_linux.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/content/gpu/gpu_sandbox_hook_linux.cc
@@ -98,8 +98,13 @@ static const char kLibV4lEncPluginPath[]
     "/usr/lib/libv4l/plugins/libv4l-encplugin.so";
 #endif
 
+#if defined(OS_LINUX)
 constexpr int dlopen_flag = RTLD_NOW | RTLD_GLOBAL | RTLD_NODELETE;
+#else
+constexpr int dlopen_flag = RTLD_NOW | RTLD_GLOBAL;
+#endif
 
+#if !defined(OS_BSD)
 void AddV4L2GpuPermissions(
     std::vector<BrokerFilePermission>* permissions,
     const sandbox::policy::SandboxSeccompBPF::Options& options) {
@@ -359,8 +364,10 @@ std::vector<BrokerFilePermission> FilePe
   AddStandardGpuPermissions(&permissions);
   return permissions;
 }
+#endif
 
 void LoadArmGpuLibraries() {
+#if !defined(OS_BSD)
   // Preload the Mali library.
   if (UseChromecastSandboxAllowlist()) {
     for (const char* path : kAllowedChromecastPaths) {
@@ -375,6 +382,7 @@ void LoadArmGpuLibraries() {
     // Preload the Tegra V4L2 (video decode acceleration) library.
     dlopen(kLibTegraPath, dlopen_flag);
   }
+#endif
 }
 
 bool LoadAmdGpuLibraries() {
@@ -414,12 +422,14 @@ void LoadV4L2Libraries(
 }
 
 void LoadChromecastV4L2Libraries() {
+#if !defined(OS_BSD)
   for (const char* path : kAllowedChromecastPaths) {
     const std::string library_path(std::string(path) +
                                    std::string("libvpcodec.so"));
     if (dlopen(library_path.c_str(), dlopen_flag))
       break;
   }
+#endif
 }
 
 bool LoadLibrariesForGpu(
@@ -441,6 +451,7 @@ bool LoadLibrariesForGpu(
   return true;
 }
 
+#if !defined(OS_BSD)
 sandbox::syscall_broker::BrokerCommandSet CommandSetForGPU(
     const sandbox::policy::SandboxLinux::Options& options) {
   sandbox::syscall_broker::BrokerCommandSet command_set;
@@ -462,13 +473,18 @@ bool BrokerProcessPreSandboxHook(
   SetProcessTitleFromCommandLine(nullptr);
   return true;
 }
+#endif
 
 }  // namespace
 
 bool GpuProcessPreSandboxHook(sandbox::policy::SandboxLinux::Options options) {
+#if defined(OS_BSD)
+  NOTIMPLEMENTED();
+#else
   sandbox::policy::SandboxLinux::GetInstance()->StartBrokerProcess(
       CommandSetForGPU(options), FilePermissionsForGpu(options),
       base::BindOnce(BrokerProcessPreSandboxHook), options);
+#endif
 
   if (!LoadLibrariesForGpu(options))
     return false;
