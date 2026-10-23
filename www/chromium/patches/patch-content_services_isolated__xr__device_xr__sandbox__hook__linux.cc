$NetBSD: patch-content_services_isolated__xr__device_xr__sandbox__hook__linux.cc,v 1.1 2026/10/23 15:05:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/services/isolated_xr_device/xr_sandbox_hook_linux.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ content/services/isolated_xr_device/xr_sandbox_hook_linux.cc
@@ -435,6 +435,7 @@ bool XrPreSandboxHook(sandbox::policy::S
       manifest ? GetRuntimeLibraryPath(manifest_path, manifest->library_path)
                : std::string();
 
+#if !BUILDFLAG(IS_BSD)
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
   instance->StartBrokerProcess(
       MakeBrokerCommandSet({
@@ -449,6 +450,7 @@ bool XrPreSandboxHook(sandbox::policy::S
           manifest_path, runtime_library_path,
           manifest ? manifest->runtime_id : XrRuntimeId::kOther),
       options);
+#endif
 
   // Pre-warm the runtime + graphics driver closure now that the broker has
   // forked, so the recursive system-library grants are unnecessary.
