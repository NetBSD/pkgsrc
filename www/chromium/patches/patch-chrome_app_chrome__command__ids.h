$NetBSD: patch-chrome_app_chrome__command__ids.h,v 1.1 2025/02/06 09:57:44 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/app/chrome_command_ids.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/app/chrome_command_ids.h
@@ -68,12 +68,12 @@
 #define IDC_TOGGLE_MULTITASK_MENU       34050
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define IDC_USE_SYSTEM_TITLE_BAR        34051
 #endif
 
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #define IDC_RESTORE_WINDOW              34052
 #endif
 
