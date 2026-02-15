$NetBSD: patch-chrome_app_chrome__command__ids.h,v 1.15 2026/02/15 09:03:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/app/chrome_command_ids.h.orig	2026-02-03 22:07:10.000000000 +0000
+++ chrome/app/chrome_command_ids.h
@@ -72,11 +72,11 @@
 #define IDC_TOGGLE_MULTITASK_MENU       34050
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define IDC_USE_SYSTEM_TITLE_BAR        34051
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define IDC_RESTORE_WINDOW              34052
 #endif
 
