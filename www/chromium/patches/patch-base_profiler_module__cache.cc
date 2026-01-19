$NetBSD: patch-base_profiler_module__cache.cc,v 1.14 2026/01/19 16:14:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/profiler/module_cache.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ base/profiler/module_cache.cc
@@ -38,7 +38,7 @@ std::string TransformModuleIDToSymbolSer
   // Android and Linux Chrome builds use the "breakpad" format to index their
   // build id, so we transform the build id for these platforms. All other
   // platforms keep their symbols indexed by the original build ID.
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Linux ELF module IDs are 160bit integers, which we need to mangle
   // down to 128bit integers to match the id that Breakpad outputs.
   // Example on version '66.0.3359.170' x64:
