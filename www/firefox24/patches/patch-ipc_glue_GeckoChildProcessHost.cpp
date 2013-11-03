$NetBSD: patch-ipc_glue_GeckoChildProcessHost.cpp,v 1.1 2013/11/03 04:51:59 ryoon Exp $

--- ipc/glue/GeckoChildProcessHost.cpp.orig	2013-07-30 00:58:17.000000000 +0000
+++ ipc/glue/GeckoChildProcessHost.cpp
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
@@ -490,7 +496,7 @@ GeckoChildProcessHost::PerformAsyncLaunc
   // and passing wstrings from one config to the other is unsafe.  So
   // we split the logic here.
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD) || defined(OS_SOLARIS)
   base::environment_map newEnvVars;
   ChildPrivileges privs = mPrivileges;
   if (privs == base::PRIVILEGES_DEFAULT) {
@@ -509,7 +515,7 @@ GeckoChildProcessHost::PerformAsyncLaunc
       if (NS_SUCCEEDED(rv)) {
         nsCString path;
         greDir->GetNativePath(path);
-# if defined(OS_LINUX) || defined(OS_BSD)
+# if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
 #  if defined(MOZ_WIDGET_ANDROID)
         path += "/lib";
 #  endif  // MOZ_WIDGET_ANDROID
@@ -618,7 +624,7 @@ GeckoChildProcessHost::PerformAsyncLaunc
   childArgv.push_back(pidstring);
 
 #if defined(MOZ_CRASHREPORTER)
-#  if defined(OS_LINUX) || defined(OS_BSD)
+#  if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
   int childCrashFd, childCrashRemapFd;
   if (!CrashReporter::CreateNotificationPipeForChild(
         &childCrashFd, &childCrashRemapFd))
@@ -651,7 +657,7 @@ GeckoChildProcessHost::PerformAsyncLaunc
   childArgv.push_back(childProcessType);
 
   base::LaunchApp(childArgv, mFileMap,
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD) || defined(OS_SOLARIS)
                   newEnvVars, privs,
 #endif
                   false, &process, arch);
