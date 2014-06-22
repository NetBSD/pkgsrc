$NetBSD: patch-mozilla_ipc_glue_GeckoChildProcessHost.cpp,v 1.10 2014/06/22 08:54:39 ryoon Exp $

--- mozilla/ipc/glue/GeckoChildProcessHost.cpp.orig	2014-06-13 00:46:08.000000000 +0000
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
 
 #if defined(XP_WIN) && defined(MOZ_CONTENT_SANDBOX)
 #include "sandboxBroker.h"
@@ -504,7 +510,7 @@ GeckoChildProcessHost::PerformAsyncLaunc
   // and passing wstrings from one config to the other is unsafe.  So
   // we split the logic here.
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD) || defined(OS_SOLARIS)
   base::environment_map newEnvVars;
   ChildPrivileges privs = mPrivileges;
   if (privs == base::PRIVILEGES_DEFAULT) {
@@ -523,7 +529,7 @@ GeckoChildProcessHost::PerformAsyncLaunc
       if (NS_SUCCEEDED(rv)) {
         nsCString path;
         greDir->GetNativePath(path);
-# if defined(OS_LINUX) || defined(OS_BSD)
+# if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
 #  if defined(MOZ_WIDGET_ANDROID)
         path += "/lib";
 #  endif  // MOZ_WIDGET_ANDROID
@@ -538,7 +544,17 @@ GeckoChildProcessHost::PerformAsyncLaunc
             newEnvVars["LD_LIBRARY_PATH"] = path.get();
         }
 # elif OS_MACOSX
-        newEnvVars["DYLD_LIBRARY_PATH"] = path.get();
+        const char *dyld_library_path = PR_GetEnv("DYLD_LIBRARY_PATH");
+        nsCString new_dyld_lib_path;
+        if (dyld_library_path && *dyld_library_path) {
+            new_dyld_lib_path.Assign(path.get());
+            new_dyld_lib_path.AppendLiteral(":");
+            new_dyld_lib_path.Append(dyld_library_path);
+            newEnvVars["DYLD_LIBRARY_PATH"] = new_dyld_lib_path.get();
+        } else {
+            newEnvVars["DYLD_LIBRARY_PATH"] = path.get();
+        }
+#   if defined(MOZ_WIDGET_COCOA)
         // XXX DYLD_INSERT_LIBRARIES should only be set when launching a plugin
         //     process, and has no effect on other subprocesses (the hooks in
         //     libplugin_child_interpose.dylib become noops).  But currently it
@@ -558,6 +574,7 @@ GeckoChildProcessHost::PerformAsyncLaunc
         interpose.Append(path.get());
         interpose.AppendLiteral("/libplugin_child_interpose.dylib");
         newEnvVars["DYLD_INSERT_LIBRARIES"] = interpose.get();
+#    endif // MOZ_WIDGET_COCOA
 # endif  // OS_LINUX
       }
     }
@@ -632,7 +649,7 @@ GeckoChildProcessHost::PerformAsyncLaunc
   childArgv.push_back(pidstring);
 
 #if defined(MOZ_CRASHREPORTER)
-#  if defined(OS_LINUX) || defined(OS_BSD)
+#  if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
   int childCrashFd, childCrashRemapFd;
   if (!CrashReporter::CreateNotificationPipeForChild(
         &childCrashFd, &childCrashRemapFd))
@@ -665,7 +682,7 @@ GeckoChildProcessHost::PerformAsyncLaunc
   childArgv.push_back(childProcessType);
 
   base::LaunchApp(childArgv, mFileMap,
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD) || defined(OS_SOLARIS)
                   newEnvVars, privs,
 #endif
                   false, &process, arch);
