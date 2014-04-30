$NetBSD: patch-xpcom_base_nsStackWalk.cpp,v 1.5 2014/04/30 15:07:18 ryoon Exp $

--- xpcom/base/nsStackWalk.cpp.orig	2014-04-18 02:04:36.000000000 +0000
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
@@ -36,7 +42,7 @@ static CriticalAddress gCriticalAddress;
      ((defined(__GNUC__) && (defined(__i386) || defined(PPC))) || \
       defined(HAVE__UNWIND_BACKTRACE)))
 
-#define NSSTACKWALK_SUPPORTS_SOLARIS \
+#define notNSSTACKWALK_SUPPORTS_SOLARIS \
     (defined(__sun) && \
      (defined(__sparc) || defined(sparc) || defined(__i386) || defined(i386)))
 
@@ -1222,9 +1228,6 @@ NS_StackWalk(NS_WalkStackCallback aCallb
 #elif defined(HAVE__UNWIND_BACKTRACE)
 
 // libgcc_s.so symbols _Unwind_Backtrace@@GCC_3.3 and _Unwind_GetIP@@GCC_3.0
-#ifndef _GNU_SOURCE
-#define _GNU_SOURCE
-#endif
 #include <unwind.h>
 
 struct unwind_info {
