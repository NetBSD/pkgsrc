$NetBSD: patch-content_app_initialize__mojo__core.cc,v 1.4 2026/11/08 15:39:03 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/app/initialize_mojo_core.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ content/app/initialize_mojo_core.cc
@@ -49,7 +49,7 @@ void InitializeMojoCore() {
     config.force_direct_shared_memory_allocation = true;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // Renderer and GPU processes create a lot of unsafe regions (data pipes,
     // large IPC payloads) and their seccomp policies allow the memfd
     // creation, sizing and sealing that base needs for one, so let them skip
