$NetBSD: patch-mozilla_toolkit_xre_nsAppRunner.cpp,v 1.5 2015/02/15 02:11:03 ryoon Exp $

--- mozilla/toolkit/xre/nsAppRunner.cpp.orig	2015-02-05 04:38:44.000000000 +0000
+++ mozilla/toolkit/xre/nsAppRunner.cpp
@@ -1768,6 +1768,18 @@ static nsresult LaunchChild(nsINativeApp
   if (NS_FAILED(rv))
     return rv;
 
+#if defined(XP_DARWIN)
+  pid_t pid = vfork();
+  if (pid == 0) { // child
+    if (execv(exePath.get(), gRestartArgv) == -1) {
+      _exit(1);
+    }
+  }
+  else if (pid == -1) {
+    return NS_ERROR_FAILURE;
+  }
+#else
+
 #if defined(XP_UNIX)
   if (execv(exePath.get(), gRestartArgv) == -1)
     return NS_ERROR_FAILURE;
@@ -1781,6 +1793,7 @@ static nsresult LaunchChild(nsINativeApp
   if (failed || exitCode)
     return NS_ERROR_FAILURE;
 #endif // XP_UNIX
+#endif // XP_DARWIN
 #endif // WP_WIN
 #endif // WP_MACOSX
 #endif // MOZ_WIDGET_ANDROID
