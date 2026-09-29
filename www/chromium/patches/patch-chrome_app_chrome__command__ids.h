$NetBSD: patch-chrome_app_chrome__command__ids.h,v 1.27 2026/09/29 07:42:47 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/app/chrome_command_ids.h.orig	2026-09-22 00:09:16.000000000 +0000
+++ chrome/app/chrome_command_ids.h
@@ -83,11 +83,11 @@
 #define IDC_TOGGLE_MULTITASK_MENU       34050
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define IDC_USE_SYSTEM_TITLE_BAR        34051
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #define IDC_RESTORE_WINDOW              34052
 #endif // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
 
