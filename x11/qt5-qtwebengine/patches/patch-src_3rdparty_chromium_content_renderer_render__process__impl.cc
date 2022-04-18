$NetBSD: patch-src_3rdparty_chromium_content_renderer_render__process__impl.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/content/renderer/render_process_impl.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/content/renderer/render_process_impl.cc
@@ -44,7 +44,7 @@
 #if defined(OS_WIN)
 #include "base/win/win_util.h"
 #endif
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(ARCH_CPU_X86_64)
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && defined(ARCH_CPU_X86_64)
 #include "v8/include/v8-wasm-trap-handler-posix.h"
 #endif
 namespace {
@@ -177,7 +177,7 @@ RenderProcessImpl::RenderProcessImpl()
 
   SetV8FlagIfNotFeature(features::kWebAssemblyTrapHandler,
                         "--no-wasm-trap-handler");
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(ARCH_CPU_X86_64)
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && defined(ARCH_CPU_X86_64)
   if (base::FeatureList::IsEnabled(features::kWebAssemblyTrapHandler)) {
     base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
     if (!command_line->HasSwitch(switches::kDisableInProcessStackTraces)) {
