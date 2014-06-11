$NetBSD: patch-xpcom_base_nsDebugImpl.cpp,v 1.1 2014/06/11 00:41:36 ryoon Exp $

--- xpcom/base/nsDebugImpl.cpp.orig	2014-05-29 23:31:50.000000000 +0000
+++ xpcom/base/nsDebugImpl.cpp
@@ -44,12 +44,43 @@
 #endif
 #endif
 
-#if defined(XP_MACOSX)
+#if defined(XP_MACOSX) || defined(__DragonFly__) || defined(__FreeBSD__) \
+ || defined(__NetBSD__) || defined(__OpenBSD__)
 #include <stdbool.h>
 #include <unistd.h>
+#include <sys/param.h>
 #include <sys/sysctl.h>
 #endif
 
+#if defined(__OpenBSD__)
+#include <sys/proc.h>
+#endif
+
+#if defined(__DragonFly__) || defined(__FreeBSD__)
+#include <sys/user.h>
+#endif
+
+#if defined(__NetBSD__)
+#undef KERN_PROC
+#define KERN_PROC KERN_PROC2
+#define KINFO_PROC struct kinfo_proc2
+#else
+#define KINFO_PROC struct kinfo_proc
+#endif
+
+#if defined(XP_MACOSX)
+#define KP_FLAGS kp_proc.p_flag
+#elif defined(__DragonFly__)
+#define KP_FLAGS kp_flags
+#elif defined(__FreeBSD__)
+#define KP_FLAGS ki_flag
+#elif defined(__OpenBSD__) && !defined(_P_TRACED)
+#define KP_FLAGS p_psflags
+#define P_TRACED PS_TRACED
+#else
+#define KP_FLAGS p_flag
+#endif
+
 #include "mozilla/mozalloc_abort.h"
 
 static void
@@ -143,16 +174,22 @@ nsDebugImpl::GetIsDebuggerAttached(bool*
 
 #if defined(XP_WIN)
   *aResult = ::IsDebuggerPresent();
-#elif defined(XP_MACOSX)
+#elif defined(XP_MACOSX) || defined(__DragonFly__) || defined(__FreeBSD__) \
+   || defined(__NetBSD__) || defined(__OpenBSD__)
   // Specify the info we're looking for
-  int mib[4];
-  mib[0] = CTL_KERN;
-  mib[1] = KERN_PROC;
-  mib[2] = KERN_PROC_PID;
-  mib[3] = getpid();
+  int mib[] = {
+    CTL_KERN,
+    KERN_PROC,
+    KERN_PROC_PID,
+    getpid(),
+#if defined(__NetBSD__) || defined(__OpenBSD__)
+    sizeof(KINFO_PROC),
+    1,
+#endif
+  };
   size_t mibSize = sizeof(mib) / sizeof(int);
 
-  struct kinfo_proc info;
+  KINFO_PROC info;
   size_t infoSize = sizeof(info);
   memset(&info, 0, infoSize);
 
@@ -162,7 +199,7 @@ nsDebugImpl::GetIsDebuggerAttached(bool*
     return NS_OK;
   }
 
-  if (info.kp_proc.p_flag & P_TRACED) {
+  if (info.KP_FLAGS & P_TRACED) {
     *aResult = true;
   }
 #endif
