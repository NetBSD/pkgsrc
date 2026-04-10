$NetBSD: patch-content_shell_renderer_shell__content__renderer__client.cc,v 1.17 2026/04/10 17:31:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/shell/renderer/shell_content_renderer_client.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ content/shell/renderer/shell_content_renderer_client.cc
@@ -56,7 +56,7 @@
 #include "components/surface_embed/renderer/create_plugin.h"
 #endif  // BUILDFLAG(ENABLE_SURFACE_EMBED)
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && \
     (defined(ARCH_CPU_X86_64) || defined(ARCH_CPU_ARM64))
 #define ENABLE_WEB_ASSEMBLY_TRAP_HANDLER_LINUX
 #include "base/debug/stack_trace.h"
