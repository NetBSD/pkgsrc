$NetBSD: patch-components_crash_core_app_crashpad__handler__main.cc,v 1.17 2026/04/10 17:31:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/crash/core/app/crashpad_handler_main.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ components/crash/core/app/crashpad_handler_main.cc
@@ -10,7 +10,7 @@
 #include "third_party/crashpad/crashpad/handler/handler_main.h"
 #include "third_party/crashpad/crashpad/handler/user_stream_data_source.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "components/stability_report/user_stream_data_source_posix.h"
 #endif
 
@@ -31,7 +31,7 @@ __attribute__((visibility("default"), us
     char* argv[]) {
   crashpad::UserStreamDataSources user_stream_data_sources;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   user_stream_data_sources.push_back(
       std::make_unique<stability_report::UserStreamDataSourcePosix>());
 #endif
