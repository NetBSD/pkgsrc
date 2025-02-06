$NetBSD: patch-base_threading_platform__thread__internal__posix.cc,v 1.1 2025/02/06 09:57:43 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/threading/platform_thread_internal_posix.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ base/threading/platform_thread_internal_posix.cc
@@ -41,7 +41,7 @@ ThreadPriorityForTest NiceValueToThreadP
 }
 
 int GetCurrentThreadNiceValue() {
-#if BUILDFLAG(IS_NACL)
+#if BUILDFLAG(IS_NACL) || BUILDFLAG(IS_BSD)
   NOTIMPLEMENTED();
   return 0;
 #else
