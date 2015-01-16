$NetBSD: patch-xpcom_base_nsStackWalk.cpp,v 1.9 2015/01/16 22:42:09 ryoon Exp $

* Replace XP_MACOSX with XP_DARWIN as the former is not defined when
  the toolkit is not cocoa.

--- xpcom/base/nsStackWalk.cpp.orig	2015-01-09 04:38:29.000000000 +0000
+++ xpcom/base/nsStackWalk.cpp
@@ -903,7 +903,7 @@ FramePointerStackWalk(NS_WalkStackCallba
         (long(next) & 3)) {
       break;
     }
-#if (defined(__ppc__) && defined(XP_MACOSX)) || defined(__powerpc64__)
+#if (defined(__ppc__) && defined(XP_DARWIN)) || defined(__powerpc64__)
     // ppc mac or powerpc64 linux
     void* pc = *(bp + 2);
     bp += 3;
@@ -933,7 +933,7 @@ FramePointerStackWalk(NS_WalkStackCallba
 }
 
 #define X86_OR_PPC (defined(__i386) || defined(PPC) || defined(__ppc__))
-#if X86_OR_PPC && (NSSTACKWALK_SUPPORTS_MACOSX || NSSTACKWALK_SUPPORTS_LINUX) // i386 or PPC Linux or Mac stackwalking code
+#if X86_OR_PPC && (NSSTACKWALK_SUPPORTS_DARWIN || NSSTACKWALK_SUPPORTS_LINUX) // i386 or PPC Linux or Mac stackwalking code
 
 EXPORT_XPCOM_API(nsresult)
 NS_StackWalk(NS_WalkStackCallback aCallback, uint32_t aSkipFrames,
