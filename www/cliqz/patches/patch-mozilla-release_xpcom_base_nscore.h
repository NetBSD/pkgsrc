$NetBSD: patch-mozilla-release_xpcom_base_nscore.h,v 1.2 2020/03/31 15:40:54 fox Exp $

* Support llvm/clang

Imported from www/firefox

--- mozilla-release/xpcom/base/nscore.h.orig	2018-11-16 08:40:07.000000000 +0000
+++ mozilla-release/xpcom/base/nscore.h
@@ -76,7 +76,7 @@
  *           NS_HIDDEN_(int) NS_FASTCALL func2(char *foo);
  */
 
-#if defined(__i386__) && defined(__GNUC__)
+#if defined(__i386__) && defined(__GNUC__) && !(defined(__clang__) && __clang_major__ == 3 && __clang_minor__ == 4 && __clang_patchlevel__ == 0)
 #  define NS_FASTCALL __attribute__((regparm(3), stdcall))
 #  define NS_CONSTRUCTOR_FASTCALL __attribute__((regparm(3), stdcall))
 #elif defined(XP_WIN) && !defined(_WIN64)
