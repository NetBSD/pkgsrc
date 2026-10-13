$NetBSD: patch-content_child_child__process.cc,v 1.29 2026/10/13 13:16:41 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/child/child_process.cc.orig	2026-10-06 00:06:58.000000000 +0000
+++ content/child/child_process.cc
@@ -37,7 +37,7 @@
 #include "content/common/android/cpu_time_metrics.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/child/sandboxed_process_thread_type_handler.h"
 #endif
 
@@ -204,7 +204,7 @@ void ChildProcess::set_main_thread(Child
   main_thread_.reset(thread);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void ChildProcess::SetIOThreadType(base::ThreadType thread_type) {
   if (!io_thread_) {
     return;
