$NetBSD: patch-chrome_browser_extensions_api_messaging_launch__context__posix.cc,v 1.14 2026/01/19 16:14:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/api/messaging/launch_context_posix.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/extensions/api/messaging/launch_context_posix.cc
@@ -84,7 +84,7 @@ std::optional<LaunchContext::ProcessStat
 
   options.current_directory = command_line.GetProgram().DirName();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Don't use no_new_privs mode, e.g. in case the host needs to use sudo.
   options.allow_new_privs = true;
 #endif
