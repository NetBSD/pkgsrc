$NetBSD: patch-base_system_sys__info.cc,v 1.26 2026/09/22 13:41:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/system/sys_info.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ base/system/sys_info.cc
@@ -247,7 +247,7 @@ std::string SysInfo::SocManufacturer() {
 #endif
 
 void SysInfo::GetHardwareInfo(base::OnceCallback<void(HardwareInfo)> callback) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   constexpr base::TaskTraits kTraits = {base::MayBlock()};
 #else
   constexpr base::TaskTraits kTraits = {};
