$NetBSD: patch-components_metrics_metrics__log.cc,v 1.2 2025/05/16 16:08:22 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/metrics/metrics_log.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ components/metrics/metrics_log.cc
@@ -62,7 +62,7 @@
 #include "base/win/current_module.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #endif
@@ -158,7 +158,7 @@ void RecordCurrentTime(
   }
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 metrics::SystemProfileProto::OS::XdgSessionType ToProtoSessionType(
     base::nix::SessionType session_type) {
   switch (session_type) {
@@ -441,7 +441,7 @@ void MetricsLog::RecordCoreSystemProfile
 // OperatingSystemVersion refers to the ChromeOS release version.
 #if BUILDFLAG(IS_CHROMEOS)
   os->set_kernel_version(base::SysInfo::KernelVersion());
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Linux operating system version is copied over into kernel version to be
   // consistent.
   os->set_kernel_version(base::SysInfo::OperatingSystemVersion());
@@ -458,7 +458,7 @@ void MetricsLog::RecordCoreSystemProfile
   os->set_build_number(base::SysInfo::GetIOSBuildNumber());
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<base::Environment> env = base::Environment::Create();
   os->set_xdg_session_type(ToProtoSessionType(base::nix::GetSessionType(*env)));
   os->set_xdg_current_desktop(
