$NetBSD: patch-chrome_browser_platform__util__linux.cc,v 1.30 2026/10/16 15:30:45 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/platform_util_linux.cc.orig	2026-10-14 21:09:54.000000000 +0000
+++ chrome/browser/platform_util_linux.cc
@@ -69,7 +69,9 @@ void OnLaunchOptionsCreated(const std::s
   argv.push_back(command);
   argv.push_back(arg);
   options.current_directory = working_directory;
+#if !BUILDFLAG(IS_BSD)
   options.allow_new_privs = true;
+#endif
   // xdg-open can fall back on mailcap which eventually might plumb through
   // to a command that needs a terminal.  Set the environment variable telling
   // it that we definitely don't have a terminal available and that it should
