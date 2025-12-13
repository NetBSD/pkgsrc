$NetBSD: patch-printing_printing__context__linux.cc,v 1.12 2025/12/13 14:53:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- printing/printing_context_linux.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ printing/printing_context_linux.cc
@@ -22,7 +22,7 @@
 #endif
 
 // Avoid using LinuxUi on Fuchsia.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -68,7 +68,7 @@ mojom::ResultCode PrintingContextLinux::
 
   ResetSettings();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ui::LinuxUi::instance())
     return mojom::ResultCode::kSuccess;
 
@@ -84,7 +84,7 @@ mojom::ResultCode PrintingContextLinux::
 }
 
 gfx::Size PrintingContextLinux::GetPdfPaperSizeDeviceUnits() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (ui::LinuxUi::instance())
     return ui::LinuxUi::instance()->GetPdfPaperSize(this);
 #endif
@@ -97,7 +97,7 @@ mojom::ResultCode PrintingContextLinux::
   DCHECK(!printer_settings.show_system_dialog);
   DCHECK(!in_print_job_);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ui::LinuxUi::instance())
     return mojom::ResultCode::kSuccess;
 
