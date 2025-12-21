$NetBSD: patch-src_3rdparty_chromium_chrome_browser_extensions_api_messaging_launch__context__posix.cc,v 1.1 2025/12/21 09:38:18 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/browser/extensions/api/messaging/launch_context_posix.cc.orig	2025-11-14 07:55:10.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/extensions/api/messaging/launch_context_posix.cc
@@ -84,7 +84,7 @@ std::optional<LaunchContext::ProcessStat
 
   options.current_directory = command_line.GetProgram().DirName();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Don't use no_new_privs mode, e.g. in case the host needs to use sudo.
   options.allow_new_privs = true;
 #endif
