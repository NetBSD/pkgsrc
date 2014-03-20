$NetBSD: patch-xpcom_base_nsStackWalk.cpp,v 1.4 2014/03/20 21:02:00 ryoon Exp $

--- xpcom/base/nsStackWalk.cpp.orig	2014-03-15 05:19:39.000000000 +0000
+++ xpcom/base/nsStackWalk.cpp
@@ -23,6 +23,12 @@ struct CriticalAddress {
 };
 static CriticalAddress gCriticalAddress;
 
+// for _Unwind_Backtrace from libcxxrt or libunwind
+// cxxabi.h from libcxxrt implicitly includes unwind.h first
+#if defined(HAVE__UNWIND_BACKTRACE) && !defined(_GNU_SOURCE)
+#define _GNU_SOURCE
+#endif
+
 #if defined(HAVE_DLOPEN) || defined(XP_MACOSX)
 #include <dlfcn.h>
 #endif
@@ -874,7 +880,7 @@ void DemangleSymbol(const char * aSymbol
 }
 
 
-#if NSSTACKWALK_SUPPORTS_SOLARIS
+#if notNSSTACKWALK_SUPPORTS_SOLARIS
 
 /*
  * Stack walking code for Solaris courtesy of Bart Smaalder's "memtrak".
@@ -1223,9 +1229,6 @@ NS_StackWalk(NS_WalkStackCallback aCallb
 #elif defined(HAVE__UNWIND_BACKTRACE)
 
 // libgcc_s.so symbols _Unwind_Backtrace@@GCC_3.3 and _Unwind_GetIP@@GCC_3.0
-#ifndef _GNU_SOURCE
-#define _GNU_SOURCE
-#endif
 #include <unwind.h>
 
 struct unwind_info {
