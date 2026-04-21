$NetBSD: patch-ui_ozone_platform_wayland_host_wayland__buffer__manager__host.cc,v 1.6 2026/04/21 15:21:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/wayland/host/wayland_buffer_manager_host.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ ui/ozone/platform/wayland/host/wayland_buffer_manager_host.cc
@@ -46,9 +46,13 @@ std::string NumberToString(uint32_t numb
 }
 
 bool CheckImportExportFence() {
+#if BUILDFLAG(IS_BSD)
+  return false;
+#else
   // DMA_BUF_IOCTL_{IMPORT,EXPORT}_SYNC_FILE was added in 6.0
   return base::SysInfo::KernelVersionNumber::Current() >=
          base::SysInfo::KernelVersionNumber(6, 0);
+#endif
 }
 
 }  // namespace
