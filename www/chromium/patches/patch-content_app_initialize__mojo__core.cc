$NetBSD: patch-content_app_initialize__mojo__core.cc,v 1.5 2026/11/19 19:46:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/app/initialize_mojo_core.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ content/app/initialize_mojo_core.cc
@@ -48,7 +48,7 @@ void InitializeMojoCore() {
     config.force_direct_shared_memory_allocation = true;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // Renderer and GPU processes create a lot of unsafe regions (data pipes,
     // large IPC payloads) and their seccomp policies allow the memfd
     // creation, sizing and sealing that base needs for one, so let them skip
