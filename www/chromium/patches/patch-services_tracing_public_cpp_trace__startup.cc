$NetBSD: patch-services_tracing_public_cpp_trace__startup.cc,v 1.3 2025/08/13 07:44:30 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/tracing/public/cpp/trace_startup.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ services/tracing/public/cpp/trace_startup.cc
@@ -66,7 +66,7 @@ void EnableStartupTracingIfNeeded(bool w
   // Create the PerfettoTracedProcess.
   if (with_thread) {
     g_tracing_with_thread = true;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     PerfettoTracedProcess::MaybeCreateInstanceWithThread(
         /*will_trace_thread_restart=*/true);
 #else
