$NetBSD: patch-ipc_chromium_src_base_process__util__posix.cc,v 1.1 2013/11/03 04:51:59 ryoon Exp $

--- ipc/chromium/src/base/process_util_posix.cc.orig	2013-05-11 19:19:32.000000000 +0000
+++ ipc/chromium/src/base/process_util_posix.cc
@@ -110,7 +110,7 @@ void CloseSuperfluousFds(const base::Inj
 #if defined(ANDROID)
   static const rlim_t kSystemDefaultMaxFds = 1024;
   static const char kFDDir[] = "/proc/self/fd";
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_SOLARIS)
   static const rlim_t kSystemDefaultMaxFds = 8192;
   static const char kFDDir[] = "/proc/self/fd";
 #elif defined(OS_MACOSX)
@@ -202,7 +202,7 @@ void CloseSuperfluousFds(const base::Inj
 // TODO(agl): Remove this function. It's fundamentally broken for multithreaded
 // apps.
 void SetAllFDsToCloseOnExec() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_SOLARIS)
   const char fd_dir[] = "/proc/self/fd";
 #elif defined(OS_MACOSX) || defined(OS_BSD)
   const char fd_dir[] = "/dev/fd";
