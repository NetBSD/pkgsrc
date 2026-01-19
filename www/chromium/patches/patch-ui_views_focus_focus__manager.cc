$NetBSD: patch-ui_views_focus_focus__manager.cc,v 1.14 2026/01/19 16:14:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/focus/focus_manager.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ ui/views/focus/focus_manager.cc
@@ -616,7 +616,7 @@ bool FocusManager::RedirectAcceleratorTo
     return false;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Processing an accelerator can delete things. Because we
   // need these objects afterwards on Linux, save widget_ as weak pointer and
   // save the close_on_deactivate property value of widget_delegate in a
@@ -631,7 +631,7 @@ bool FocusManager::RedirectAcceleratorTo
   const bool accelerator_processed =
       focus_manager->ProcessAccelerator(accelerator);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Need to manually close the bubble widget on Linux. On Linux when the
   // bubble is shown, the main widget remains active. Because of that when
   // focus is set to the main widget to process accelerator, the main widget
