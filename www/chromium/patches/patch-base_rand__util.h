$NetBSD: patch-base_rand__util.h,v 1.14 2026/01/19 16:14:07 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/rand_util.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ base/rand_util.h
@@ -213,7 +213,7 @@ void RandomShuffle(Itr first, Itr last) 
   std::shuffle(first, last, RandomBitGenerator());
 }
 
-#if BUILDFLAG(IS_POSIX)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_BSD)
 BASE_EXPORT int GetUrandomFD();
 #endif
 
