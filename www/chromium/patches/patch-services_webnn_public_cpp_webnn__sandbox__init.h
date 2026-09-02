$NetBSD: patch-services_webnn_public_cpp_webnn__sandbox__init.h,v 1.1 2026/09/02 13:13:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/webnn/public/cpp/webnn_sandbox_init.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ services/webnn/public/cpp/webnn_sandbox_init.h
@@ -10,7 +10,7 @@
 
 namespace webnn {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Preloads WebNN LiteRT libraries (like the GPU accelerator DLL) before the
 // GPU process sandbox is locked down.
 COMPONENT_EXPORT(WEBNN_PUBLIC_CPP)
