$NetBSD: patch-content_child_child__process.h,v 1.7 2025/09/12 16:02:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/child/child_process.h.orig	2025-09-08 23:21:33.000000000 +0000
+++ content/child/child_process.h
@@ -79,7 +79,7 @@ class CONTENT_EXPORT ChildProcess {
     return io_thread_runner_.get();
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Changes the thread type of the child process IO thread.
   void SetIOThreadType(base::ThreadType thread_type);
 #endif
