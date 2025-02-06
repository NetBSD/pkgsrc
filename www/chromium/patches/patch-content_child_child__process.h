$NetBSD: patch-content_child_child__process.h,v 1.1 2025/02/06 09:58:07 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/child/child_process.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/child/child_process.h
@@ -79,7 +79,7 @@ class CONTENT_EXPORT ChildProcess {
     return io_thread_runner_.get();
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Changes the thread type of the child process IO thread.
   void SetIOThreadType(base::ThreadType thread_type);
 #endif
