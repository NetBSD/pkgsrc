$NetBSD: patch-mojo_core_embedder_configuration.h,v 1.3 2026/10/23 15:05:30 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- mojo/core/embedder/configuration.h.orig	2026-10-19 20:07:21.000000000 +0000
+++ mojo/core/embedder/configuration.h
@@ -33,7 +33,7 @@ struct Configuration {
   // objects.
   bool force_direct_shared_memory_allocation = false;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // If `true` and this process delegates shared memory allocation to the
   // broker, unsafe regions (which never need a read-only handle) are still
   // created directly in this process. That takes memfd_create(), ftruncate()
