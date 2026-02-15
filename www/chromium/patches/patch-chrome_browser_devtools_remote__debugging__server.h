$NetBSD: patch-chrome_browser_devtools_remote__debugging__server.h,v 1.11 2026/02/15 09:03:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/devtools/remote_debugging_server.h.orig	2026-02-03 22:07:10.000000000 +0000
+++ chrome/browser/devtools/remote_debugging_server.h
@@ -43,7 +43,7 @@ class RemoteDebuggingServer {
 
   static void EnableTetheringForDebug();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Enables the default user data dir check even for non-Chrome branded builds,
   // for testing.
   static void EnableDefaultUserDataDirCheckForTesting();
