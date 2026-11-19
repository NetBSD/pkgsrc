$NetBSD: patch-chrome_services_printing_print__backend__service__impl.h,v 1.19 2026/11/19 19:45:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/services/printing/print_backend_service_impl.h.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/services/printing/print_backend_service_impl.h
@@ -28,7 +28,7 @@
 #include "printing/printing_context.h"
 #include "ui/gfx/native_ui_types.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "printing/printing_context_linux.h"
 #endif
 
@@ -242,7 +242,7 @@ class PrintBackendServiceImpl : public m
 
   scoped_refptr<PrintBackend> print_backend_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<PrintingContextLinux::PrintDialogFactory>
       print_dialog_factory_;
 #endif
