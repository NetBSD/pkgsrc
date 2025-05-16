$NetBSD: patch-remoting_base_chromoting__event.cc,v 1.2 2025/05/16 16:08:29 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/base/chromoting_event.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ remoting/base/chromoting_event.cc
@@ -191,7 +191,7 @@ void ChromotingEvent::AddSystemInfo() {
   SetString(kCpuKey, base::SysInfo::OperatingSystemArchitecture());
   SetString(kOsVersionKey, base::SysInfo::OperatingSystemVersion());
   SetString(kWebAppVersionKey, STRINGIZE(VERSION));
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   Os os = Os::CHROMOTING_LINUX;
 #elif BUILDFLAG(IS_CHROMEOS)
   Os os = Os::CHROMOTING_CHROMEOS;
