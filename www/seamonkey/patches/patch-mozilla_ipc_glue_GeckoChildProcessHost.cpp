$NetBSD: patch-mozilla_ipc_glue_GeckoChildProcessHost.cpp,v 1.6 2013/01/07 21:55:30 ryoon Exp $

--- mozilla/ipc/glue/GeckoChildProcessHost.cpp.orig	2012-11-18 10:19:38.000000000 +0000
+++ mozilla/ipc/glue/GeckoChildProcessHost.cpp
@@ -4,7 +4,13 @@
  * License, v. 2.0. If a copy of the MPL was not distributed with this
  * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
+#if defined(__NetBSD__)
+_Pragma("GCC visibility push(default)")
+#endif
 #include "GeckoChildProcessHost.h"
+#if defined(__NetBSD__)
+_Pragma("GCC visibility pop")
+#endif
 
 #include "base/command_line.h"
 #include "base/path_service.h"
@@ -437,7 +443,7 @@ GeckoChildProcessHost::PerformAsyncLaunc
   // and passing wstrings from one config to the other is unsafe.  So
   // we split the logic here.
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   base::environment_map newEnvVars;
   base::ChildPrivileges privs = kLowRightsSubprocesses ?
                                 base::UNPRIVILEGED :
@@ -455,8 +461,8 @@ GeckoChildProcessHost::PerformAsyncLaunc
       if (NS_SUCCEEDED(rv)) {
         nsCString path;
         greDir->GetNativePath(path);
-# ifdef OS_LINUX
-#  ifdef MOZ_WIDGET_ANDROID
+# if defined(OS_LINUX) || defined(OS_BSD)
+#  if defined(MOZ_WIDGET_ANDROID) || defined(OS_BSD)
         path += "/lib";
 #  endif  // MOZ_WIDGET_ANDROID
         const char *ld_library_path = PR_GetEnv("LD_LIBRARY_PATH");
@@ -575,7 +581,7 @@ GeckoChildProcessHost::PerformAsyncLaunc
   childArgv.push_back(pidstring);
 
 #if defined(MOZ_CRASHREPORTER)
-#  if defined(OS_LINUX)
+#  if defined(OS_LINUX) || defined(OS_BSD)
   int childCrashFd, childCrashRemapFd;
   if (!CrashReporter::CreateNotificationPipeForChild(
         &childCrashFd, &childCrashRemapFd))
@@ -612,7 +618,7 @@ GeckoChildProcessHost::PerformAsyncLaunc
 #endif
 
   base::LaunchApp(childArgv, mFileMap,
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
                   newEnvVars, privs,
 #endif
                   false, &process, arch);
