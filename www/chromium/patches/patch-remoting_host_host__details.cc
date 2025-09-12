$NetBSD: patch-remoting_host_host__details.cc,v 1.7 2025/09/12 16:02:32 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/host_details.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ remoting/host/host_details.cc
@@ -7,7 +7,7 @@
 #include "base/system/sys_info.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/linux_util.h"
 #endif
 
@@ -22,7 +22,7 @@ std::string GetHostOperatingSystemName()
   return "Mac";
 #elif BUILDFLAG(IS_CHROMEOS)
   return "ChromeOS";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "Linux";
 #elif BUILDFLAG(IS_ANDROID)
   return "Android";
@@ -34,7 +34,7 @@ std::string GetHostOperatingSystemName()
 // Get the host Operating System Version, removing the need to check for OS
 // definitions and keeps the format used consistent.
 std::string GetHostOperatingSystemVersion() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return base::GetLinuxDistro();
 #else
   return base::SysInfo::OperatingSystemVersion();
