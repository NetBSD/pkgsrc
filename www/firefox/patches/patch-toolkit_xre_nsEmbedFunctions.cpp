$NetBSD: patch-toolkit_xre_nsEmbedFunctions.cpp,v 1.4 2014/05/29 15:38:19 pho Exp $

* Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- toolkit/xre/nsEmbedFunctions.cpp.orig	2014-05-06 22:56:36.000000000 +0000
+++ toolkit/xre/nsEmbedFunctions.cpp
@@ -42,7 +42,7 @@
 #include "nsXREDirProvider.h"
 
 #include "mozilla/Omnijar.h"
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
 #include "nsVersionComparator.h"
 #include "chrome/common/mach_ipc_mac.h"
 #endif
@@ -228,9 +228,9 @@ XRE_TakeMinidumpForChild(uint32_t aChild
 bool
 XRE_SetRemoteExceptionHandler(const char* aPipe/*= 0*/)
 {
-#if defined(XP_WIN) || defined(XP_MACOSX)
+#if defined(XP_WIN) || defined(MOZ_WIDGET_COCOA)
   return CrashReporter::SetRemoteExceptionHandler(nsDependentCString(aPipe));
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_SOLARIS)
   return CrashReporter::SetRemoteExceptionHandler();
 #else
 #  error "OOP crash reporter unsupported on this platform"
@@ -306,7 +306,7 @@ XRE_InitChildProcess(int aArgc,
 
   // Complete 'task_t' exchange for Mac OS X. This structure has the same size
   // regardless of architecture so we don't have any cross-arch issues here.
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   if (aArgc < 1)
     return NS_ERROR_FAILURE;
   const char* const mach_port_name = aArgv[--aArgc];
@@ -359,7 +359,7 @@ XRE_InitChildProcess(int aArgc,
     return NS_ERROR_FAILURE;
   const char* const crashReporterArg = aArgv[--aArgc];
   
-#  if defined(XP_WIN) || defined(XP_MACOSX)
+#  if defined(XP_WIN) || defined(MOZ_WIDGET_COCOA)
   // on windows and mac, |crashReporterArg| is the named pipe on which the
   // server is listening for requests, or "-" if crash reporting is
   // disabled.
@@ -368,7 +368,7 @@ XRE_InitChildProcess(int aArgc,
     // Bug 684322 will add better visibility into this condition
     NS_WARNING("Could not setup crash reporting\n");
   }
-#  elif defined(OS_LINUX)
+#  elif defined(OS_LINUX) || defined(OS_SOLARIS)
   // on POSIX, |crashReporterArg| is "true" if crash reporting is
   // enabled, false otherwise
   if (0 != strcmp("false", crashReporterArg) && 
@@ -636,7 +636,7 @@ XRE_RunAppShell()
 {
     nsCOMPtr<nsIAppShell> appShell(do_GetService(kAppShellCID));
     NS_ENSURE_TRUE(appShell, NS_ERROR_FAILURE);
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     {
       // In content processes that want XPCOM (and hence want
       // AppShell), we usually run our hybrid event loop through
@@ -675,7 +675,7 @@ XRE_RunAppShell()
 
       loop->SetNestableTasksAllowed(couldNest);
     }
-#endif  // XP_MACOSX
+#endif  // MOZ_WIDGET_COCOA
     return appShell->Run();
 }
 
@@ -701,7 +701,7 @@ XRE_ShutdownChildProcess()
   //  (4) ProcessChild joins the IO thread
   //  (5) exit()
   MessageLoop::current()->Quit();
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
   nsCOMPtr<nsIAppShell> appShell(do_GetService(kAppShellCID));
   if (appShell) {
       // On Mac, we might be only above nsAppShell::Run(), not
@@ -710,7 +710,7 @@ XRE_ShutdownChildProcess()
       // above MessagePump::Run(), this Exit() is just superfluous.
       appShell->Exit();
   }
-#endif // XP_MACOSX
+#endif // MOZ_WIDGET_COCOA
 }
 
 namespace {
