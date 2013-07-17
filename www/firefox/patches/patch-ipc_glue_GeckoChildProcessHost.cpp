$NetBSD: patch-ipc_glue_GeckoChildProcessHost.cpp,v 1.2 2013/07/17 11:00:13 jperkin Exp $

--- ipc/glue/GeckoChildProcessHost.cpp.orig	2013-06-18 11:01:23.000000000 +0000
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
@@ -494,7 +500,7 @@ GeckoChildProcessHost::PerformAsyncLaunc
   // and passing wstrings from one config to the other is unsafe.  So
   // we split the logic here.
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD) || defined(OS_SOLARIS)
   base::environment_map newEnvVars;
   ChildPrivileges privs = mPrivileges;
   if (privs == base::PRIVILEGES_DEFAULT) {
@@ -513,7 +519,7 @@ GeckoChildProcessHost::PerformAsyncLaunc
       if (NS_SUCCEEDED(rv)) {
         nsCString path;
         greDir->GetNativePath(path);
-# if defined(OS_LINUX) || defined(OS_BSD)
+# if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
 #  if defined(MOZ_WIDGET_ANDROID)
         path += "/lib";
 #  endif  // MOZ_WIDGET_ANDROID
@@ -636,7 +642,7 @@ GeckoChildProcessHost::PerformAsyncLaunc
   childArgv.push_back(pidstring);
 
 #if defined(MOZ_CRASHREPORTER)
-#  if defined(OS_LINUX) || defined(OS_BSD)
+#  if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
   int childCrashFd, childCrashRemapFd;
   if (!CrashReporter::CreateNotificationPipeForChild(
         &childCrashFd, &childCrashRemapFd))
@@ -673,7 +679,7 @@ GeckoChildProcessHost::PerformAsyncLaunc
 #endif
 
   base::LaunchApp(childArgv, mFileMap,
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD) || defined(OS_SOLARIS)
                   newEnvVars, privs,
 #endif
                   false, &process, arch);
