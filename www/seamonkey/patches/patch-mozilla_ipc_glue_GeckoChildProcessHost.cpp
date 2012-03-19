$NetBSD: patch-mozilla_ipc_glue_GeckoChildProcessHost.cpp,v 1.2 2012/03/19 10:35:59 ryoon Exp $

--- mozilla/ipc/glue/GeckoChildProcessHost.cpp.orig	2012-03-13 05:32:39.000000000 +0000
+++ mozilla/ipc/glue/GeckoChildProcessHost.cpp
@@ -430,7 +430,7 @@ GeckoChildProcessHost::PerformAsyncLaunc
   // and passing wstrings from one config to the other is unsafe.  So
   // we split the logic here.
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   base::environment_map newEnvVars;
   // XPCOM may not be initialized in some subprocesses.  We don't want
   // to initialize XPCOM just for the directory service, especially
@@ -445,8 +445,8 @@ GeckoChildProcessHost::PerformAsyncLaunc
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
@@ -557,7 +557,7 @@ GeckoChildProcessHost::PerformAsyncLaunc
   childArgv.push_back(pidstring);
 
 #if defined(MOZ_CRASHREPORTER)
-#  if defined(OS_LINUX)
+#  if defined(OS_LINUX) || defined(OS_BSD)
   int childCrashFd, childCrashRemapFd;
   if (!CrashReporter::CreateNotificationPipeForChild(
         &childCrashFd, &childCrashRemapFd))
@@ -594,7 +594,7 @@ GeckoChildProcessHost::PerformAsyncLaunc
 #endif
 
   base::LaunchApp(childArgv, mFileMap,
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
                   newEnvVars,
 #endif
                   false, &process, arch);
