$NetBSD: patch-src_3rdparty_chromium_services_tracing_public_cpp_stack__sampling_tracing__sampler__profiler.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/services/tracing/public/cpp/stack_sampling/tracing_sampler_profiler.cc.orig	2020-07-15 18:56:47.000000000 +0000
+++ src/3rdparty/chromium/services/tracing/public/cpp/stack_sampling/tracing_sampler_profiler.cc
@@ -525,7 +525,7 @@ void TracingSamplerProfiler::TracingProf
 
 // static
 void TracingSamplerProfiler::MangleModuleIDIfNeeded(std::string* module_id) {
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
   // Linux ELF module IDs are 160bit integers, which we need to mangle
   // down to 128bit integers to match the id that Breakpad outputs.
   // Example on version '66.0.3359.170' x64:
