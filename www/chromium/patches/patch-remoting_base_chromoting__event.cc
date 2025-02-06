$NetBSD: patch-remoting_base_chromoting__event.cc,v 1.1 2025/02/06 09:58:17 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/base/chromoting_event.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ remoting/base/chromoting_event.cc
@@ -192,7 +192,7 @@ void ChromotingEvent::AddSystemInfo() {
   SetString(kCpuKey, base::SysInfo::OperatingSystemArchitecture());
   SetString(kOsVersionKey, base::SysInfo::OperatingSystemVersion());
   SetString(kWebAppVersionKey, STRINGIZE(VERSION));
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   Os os = Os::CHROMOTING_LINUX;
 #elif BUILDFLAG(IS_CHROMEOS_ASH)
   Os os = Os::CHROMOTING_CHROMEOS;
