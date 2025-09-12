$NetBSD: patch-chrome_browser_platform__util__linux.cc,v 1.7 2025/09/12 16:02:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/platform_util_linux.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ chrome/browser/platform_util_linux.cc
@@ -302,7 +302,9 @@ void OnLaunchOptionsCreated(const std::s
   argv.push_back(command);
   argv.push_back(arg);
   options.current_directory = working_directory;
+#if !BUILDFLAG(IS_BSD)
   options.allow_new_privs = true;
+#endif
   // xdg-open can fall back on mailcap which eventually might plumb through
   // to a command that needs a terminal.  Set the environment variable telling
   // it that we definitely don't have a terminal available and that it should
