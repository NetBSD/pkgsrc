$NetBSD: patch-mozilla_toolkit_xre_nsAppRunner.cpp,v 1.3 2014/06/22 08:54:39 ryoon Exp $

--- mozilla/toolkit/xre/nsAppRunner.cpp.orig	2014-06-13 00:46:13.000000000 +0000
+++ mozilla/toolkit/xre/nsAppRunner.cpp
@@ -1715,6 +1715,16 @@ static nsresult LaunchChild(nsINativeApp
 #elif defined(XP_OS2)
   if (_execv(exePath.get(), gRestartArgv) == -1)
     return NS_ERROR_FAILURE;
+#elif defined(XP_DARWIN)
+  pid_t pid = fork();
+  if (pid == 0) { // child
+      if (execv(exePath.get(), gRestartArgv) == -1) {
+          _exit(1);
+      }
+  }
+  else if (pid == -1) {
+      return NS_ERROR_FAILURE;
+  }
 #elif defined(XP_UNIX)
   if (execv(exePath.get(), gRestartArgv) == -1)
     return NS_ERROR_FAILURE;
