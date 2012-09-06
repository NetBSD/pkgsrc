$NetBSD: patch-ipc_chromium_src_base_debug__util__posic.cc,v 1.6 2012/09/06 12:08:51 ryoon Exp $

--- mozilla/ipc/chromium/src/base/debug_util_posix.cc.orig	2012-08-27 04:49:15.000000000 +0000
+++ mozilla/ipc/chromium/src/base/debug_util_posix.cc
@@ -5,7 +5,7 @@
 #include "build/build_config.h"
 #include "base/debug_util.h"
 
-#define MOZ_HAVE_EXECINFO_H (!defined(ANDROID) && !defined(__OpenBSD__))
+#define MOZ_HAVE_EXECINFO_H (defined(OS_LINUX) && !defined(ANDROID))
 
 #include <errno.h>
 #include <fcntl.h>
@@ -17,9 +17,16 @@
 #include <unistd.h>
 #if MOZ_HAVE_EXECINFO_H
 #include <execinfo.h>
+#endif
+
+#if defined(OS_MACOSX) || defined(OS_BSD)
 #include <sys/sysctl.h>
 #endif
 
+#if defined(OS_DRAGONFLY) || defined(OS_FREEBSD)
+#include <sys/user.h>
+#endif
+
 #include "base/basictypes.h"
 #include "base/eintr_wrapper.h"
 #include "base/logging.h"
@@ -32,7 +39,7 @@ bool DebugUtil::SpawnDebuggerOnProcess(u
   return false;
 }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 
 // Based on Apple's recommended method as described in
 // http://developer.apple.com/qa/qa2004/qa1361.html
@@ -71,7 +78,15 @@ bool DebugUtil::BeingDebugged() {
 
   // This process is being debugged if the P_TRACED flag is set.
   is_set = true;
+#if defined(OS_DRAGONFLY)
+  being_debugged = (info.kp_flags & P_TRACED) != 0;
+#elif defined(OS_FREEBSD)
+  being_debugged = (info.ki_flag & P_TRACED) != 0;
+#elif defined(OS_OPENBSD)
+  being_debugged = (info.p_flag & P_TRACED) != 0;
+#else
   being_debugged = (info.kp_proc.p_flag & P_TRACED) != 0;
+#endif
   return being_debugged;
 }
 
