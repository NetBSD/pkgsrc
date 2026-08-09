$NetBSD: patch-agents_skills_magi-mode_tests_testdata_mock__app.cc,v 1.1 2026/08/09 06:31:05 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- agents/skills/magi-mode/tests/testdata/mock_app.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ agents/skills/magi-mode/tests/testdata/mock_app.cc
@@ -14,7 +14,7 @@
 #include "file_manager_win.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "socket_handler_linux.h"
 #endif
 
@@ -39,7 +39,7 @@ void RunMockApp() {
   ProcessFile();
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ReadConfig();
 #endif
 }
