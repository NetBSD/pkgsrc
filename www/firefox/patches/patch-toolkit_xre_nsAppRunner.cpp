$NetBSD: patch-toolkit_xre_nsAppRunner.cpp,v 1.3 2014/06/06 01:05:50 pho Exp $

MacOS X < 10.6 had an undocumented behavior concerning execve(2)
inside a threaded process. If a process tried to call execve(2) and
had more than one active thread, the kernel returned ENOTSUP. So we
have to either fork(2) or vfork(2) before calling execve(2) to make
sure the caller is single-threaded as otherwise the application fails
to restart itself.

__mac_execve() in XNU 1228 (Darwin 9, MacOS X 10.5) had the
restriction:
http://www.opensource.apple.com/source/xnu/xnu-1228.15.4/bsd/kern/kern_exec.c

In XNU 1456 (Darwin 10, MacOS X 10.6) the multi-threaded check
disappeared:
http://www.opensource.apple.com/source/xnu/xnu-1456.1.26/bsd/kern/kern_exec.c

--- toolkit/xre/nsAppRunner.cpp.orig	2014-05-06 22:56:36.000000000 +0000
+++ toolkit/xre/nsAppRunner.cpp
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
