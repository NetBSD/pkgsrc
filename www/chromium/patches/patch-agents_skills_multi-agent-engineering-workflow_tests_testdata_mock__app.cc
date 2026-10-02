$NetBSD: patch-agents_skills_multi-agent-engineering-workflow_tests_testdata_mock__app.cc,v 1.3 2026/10/02 11:43:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- agents/skills/multi-agent-engineering-workflow/tests/testdata/mock_app.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ agents/skills/multi-agent-engineering-workflow/tests/testdata/mock_app.cc
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
