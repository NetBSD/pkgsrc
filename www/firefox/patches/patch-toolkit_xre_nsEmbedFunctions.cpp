$NetBSD: patch-toolkit_xre_nsEmbedFunctions.cpp,v 1.7 2017/06/14 11:28:44 ryoon Exp $

* Support Solaris

--- toolkit/xre/nsEmbedFunctions.cpp.orig	2017-06-05 20:45:23.000000000 +0000
+++ toolkit/xre/nsEmbedFunctions.cpp
@@ -285,7 +285,7 @@ XRE_SetRemoteExceptionHandler(const char
 {
 #if defined(XP_WIN) || defined(XP_MACOSX)
   return CrashReporter::SetRemoteExceptionHandler(nsDependentCString(aPipe));
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_SOLARIS)
   return CrashReporter::SetRemoteExceptionHandler();
 #else
 #  error "OOP crash reporter unsupported on this platform"
@@ -504,7 +504,7 @@ XRE_InitChildProcess(int aArgc,
     // Bug 684322 will add better visibility into this condition
     NS_WARNING("Could not setup crash reporting\n");
   }
-#  elif defined(OS_LINUX)
+#  elif defined(OS_LINUX) || defined(OS_SOLARIS)
   // on POSIX, |crashReporterArg| is "true" if crash reporting is
   // enabled, false otherwise
   if (0 != strcmp("false", crashReporterArg) &&
