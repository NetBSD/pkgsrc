$NetBSD: patch-chrome_browser_ui_views_chrome__browser__main__extra__parts__views.cc,v 1.19 2026/05/10 15:29:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/chrome_browser_main_extra_parts_views.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/ui/views/chrome_browser_main_extra_parts_views.cc
@@ -39,7 +39,7 @@
 #include "ui/wm/core/wm_state.h"
 #endif  // defined(USE_AURA)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -126,7 +126,7 @@ void ChromeBrowserMainExtraPartsViews::P
         return controller;
       }));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On the Linux desktop, we want to prevent the user from logging in as root,
   // so that we don't destroy the profile. Now that we have some minimal ui
   // initialized, check to see if we're running as root and bail if we are.
