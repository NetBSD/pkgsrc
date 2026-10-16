$NetBSD: patch-content_app_initialize__mojo__core.cc,v 1.2 2026/10/16 15:30:53 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/app/initialize_mojo_core.cc.orig	2026-10-14 21:09:54.000000000 +0000
+++ content/app/initialize_mojo_core.cc
@@ -54,7 +54,7 @@ void InitializeMojoCore() {
         mojo::core::kMojoDirectSharedMemoryAllocation);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // Renderer and GPU processes create a lot of unsafe regions (data pipes,
     // large IPC payloads) and their seccomp policies allow the memfd
     // creation, sizing and sealing that base needs for one, so let them skip
