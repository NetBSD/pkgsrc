$NetBSD: patch-mozilla_toolkit_xre_nsEmbedFunctions.cpp,v 1.1 2013/08/11 03:18:46 ryoon Exp $

--- mozilla/toolkit/xre/nsEmbedFunctions.cpp.orig	2013-08-04 03:05:52.000000000 +0000
+++ mozilla/toolkit/xre/nsEmbedFunctions.cpp
@@ -239,7 +239,7 @@ XRE_SetRemoteExceptionHandler(const char
 {
 #if defined(XP_WIN) || defined(XP_MACOSX)
   return CrashReporter::SetRemoteExceptionHandler(nsDependentCString(aPipe));
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_SOLARIS)
   return CrashReporter::SetRemoteExceptionHandler();
 #else
 #  error "OOP crash reporter unsupported on this platform"
@@ -351,7 +351,7 @@ XRE_InitChildProcess(int aArgc,
     // Bug 684322 will add better visibility into this condition
     NS_WARNING("Could not setup crash reporting\n");
   }
-#  elif defined(OS_LINUX)
+#  elif defined(OS_LINUX) || defined(OS_SOLARIS)
   // on POSIX, |crashReporterArg| is "true" if crash reporting is
   // enabled, false otherwise
   if (0 != strcmp("false", crashReporterArg) && 
