$NetBSD: patch-dom_base_nsWrapperCache.h,v 1.1 2017/09/12 07:39:08 martin Exp $

See https://bugzilla.mozilla.org/show_bug.cgi?id=1398677
Allow building on other 64bit architectures.

--- dom/base/nsWrapperCache.h.orig	2017-07-31 18:20:52.000000000 +0200
+++ dom/base/nsWrapperCache.h	2017-09-11 08:32:36.713346387 +0200
@@ -41,7 +41,7 @@ class nsWindowRoot;
 // This may waste space for some other nsWrapperCache-derived objects that have
 // a 32-bit field as their first member, but those objects are unlikely to be as
 // numerous or performance-critical as DOM nodes.
-#if defined(_M_X64) || defined(__x86_64__) || defined(__aarch64__)
+#if defined(_M_X64) || defined(__x86_64__) || defined(__aarch64__) || defined(__LP64__)
 static_assert(sizeof(void*) == 8, "These architectures should be 64-bit");
 #define BOOL_FLAGS_ON_WRAPPER_CACHE
 #else
