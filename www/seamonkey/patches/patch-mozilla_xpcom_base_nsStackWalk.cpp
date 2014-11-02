$NetBSD: patch-mozilla_xpcom_base_nsStackWalk.cpp,v 1.4 2014/11/02 05:40:31 ryoon Exp $

--- mozilla/xpcom/base/nsStackWalk.cpp.orig	2014-10-14 06:36:46.000000000 +0000
+++ mozilla/xpcom/base/nsStackWalk.cpp
@@ -47,7 +47,7 @@ static CriticalAddress gCriticalAddress;
   (defined(__sun) && \
    (defined(__sparc) || defined(sparc) || defined(__i386) || defined(i386)))
 
-#if NSSTACKWALK_SUPPORTS_MACOSX
+#if NSSTACKWALK_SUPPORTS_DARWIN
 #include <pthread.h>
 #include <CoreServices/CoreServices.h>
 
@@ -866,7 +866,7 @@ NS_FormatCodeAddressDetails(void* aPC, c
 
 // WIN32 x86 stack walking code
 // i386 or PPC Linux stackwalking code or Solaris
-#elif HAVE_DLADDR && (HAVE__UNWIND_BACKTRACE || NSSTACKWALK_SUPPORTS_LINUX || NSSTACKWALK_SUPPORTS_SOLARIS || NSSTACKWALK_SUPPORTS_MACOSX)
+#elif HAVE_DLADDR && (HAVE__UNWIND_BACKTRACE || NSSTACKWALK_SUPPORTS_LINUX || NSSTACKWALK_SUPPORTS_SOLARIS || NSSTACKWALK_SUPPORTS_DARWIN)
 
 #include <stdlib.h>
 #include <string.h>
@@ -1191,7 +1191,7 @@ FramePointerStackWalk(NS_WalkStackCallba
         (long(next) & 3)) {
       break;
     }
-#if (defined(__ppc__) && defined(XP_MACOSX)) || defined(__powerpc64__)
+#if (defined(__ppc__) && defined(XP_DARWIN)) || defined(__powerpc64__)
     // ppc mac or powerpc64 linux
     void* pc = *(bp + 2);
     bp += 3;
@@ -1221,7 +1221,7 @@ FramePointerStackWalk(NS_WalkStackCallba
 }
 
 #define X86_OR_PPC (defined(__i386) || defined(PPC) || defined(__ppc__))
-#if X86_OR_PPC && (NSSTACKWALK_SUPPORTS_MACOSX || NSSTACKWALK_SUPPORTS_LINUX) // i386 or PPC Linux or Mac stackwalking code
+#if X86_OR_PPC && (NSSTACKWALK_SUPPORTS_DARWIN || NSSTACKWALK_SUPPORTS_LINUX) // i386 or PPC Linux or Mac stackwalking code
 
 EXPORT_XPCOM_API(nsresult)
 NS_StackWalk(NS_WalkStackCallback aCallback, uint32_t aSkipFrames,
