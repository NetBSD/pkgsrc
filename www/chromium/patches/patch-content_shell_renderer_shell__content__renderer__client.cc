$NetBSD: patch-content_shell_renderer_shell__content__renderer__client.cc,v 1.16 2026/03/14 12:40:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/shell/renderer/shell_content_renderer_client.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ content/shell/renderer/shell_content_renderer_client.cc
@@ -56,7 +56,7 @@
 #include "components/surface_embed/renderer/create_plugin.h"
 #endif  // BUILDFLAG(ENABLE_SURFACE_EMBED)
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && \
     (defined(ARCH_CPU_X86_64) || defined(ARCH_CPU_ARM64))
 #define ENABLE_WEB_ASSEMBLY_TRAP_HANDLER_LINUX
 #include "base/debug/stack_trace.h"
