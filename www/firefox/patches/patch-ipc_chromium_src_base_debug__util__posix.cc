$NetBSD: patch-ipc_chromium_src_base_debug__util__posix.cc,v 1.3 2014/02/20 13:19:03 ryoon Exp $

--- ipc/chromium/src/base/debug_util_posix.cc.orig	2013-05-11 19:19:32.000000000 +0000
+++ ipc/chromium/src/base/debug_util_posix.cc
@@ -107,7 +107,7 @@ bool DebugUtil::BeingDebugged() {
   return being_debugged;
 }
 
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_SOLARIS)
 
 // We can look in /proc/self/status for TracerPid.  We are likely used in crash
 // handling, so we are careful not to use the heap or have side effects.
