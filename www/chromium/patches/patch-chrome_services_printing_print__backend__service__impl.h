$NetBSD: patch-chrome_services_printing_print__backend__service__impl.h,v 1.4 2026/04/21 15:21:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/services/printing/print_backend_service_impl.h.orig	2026-04-14 23:31:37.000000000 +0200
+++ chrome/services/printing/print_backend_service_impl.h
@@ -35,7 +35,7 @@
 #include "mojo/public/cpp/bindings/remote.h"
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "printing/printing_context_linux.h"
 #endif
 
@@ -270,7 +270,7 @@ class PrintBackendServiceImpl : public m
 
   scoped_refptr<PrintBackend> print_backend_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<PrintingContextLinux::PrintDialogFactory>
       print_dialog_factory_;
 #endif
