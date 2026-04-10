$NetBSD: patch-remoting_base_environment__details.cc,v 1.4 2026/04/10 17:31:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/base/environment_details.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ remoting/base/environment_details.cc
@@ -9,7 +9,7 @@
 #include "build/build_config.h"
 #include "remoting/base/version.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/linux_util.h"
 #endif
 
@@ -28,7 +28,7 @@ std::string GetOperatingSystemName() {
   return "Mac";
 #elif BUILDFLAG(IS_CHROMEOS)
   return "ChromeOS";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "Linux";
 #elif BUILDFLAG(IS_ANDROID)
   return "Android";
@@ -40,7 +40,7 @@ std::string GetOperatingSystemName() {
 // Get the Operating System Version, removing the need to check for OS
 // definitions and keeps the format used consistent.
 std::string GetOperatingSystemVersion() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return base::GetLinuxDistro();
 #else
   return base::SysInfo::OperatingSystemVersion();
