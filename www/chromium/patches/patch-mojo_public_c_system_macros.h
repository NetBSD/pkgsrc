$NetBSD: patch-mojo_public_c_system_macros.h,v 1.1 2026/11/19 19:46:03 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- mojo/public/c/system/macros.h.orig	2026-11-11 21:01:38.000000000 +0000
+++ mojo/public/c/system/macros.h
@@ -10,7 +10,11 @@
 
 #if !defined(__cplusplus)
 #include <assert.h>    // Defines static_assert() in C11.
+#if __has_include(<stdalign.h>)
 #include <stdalign.h>  // Defines alignof() in C11.
+#else
+#define alignof _Alignof
+#endif
 #endif
 
 // Assert things at compile time. (|msg| should be a valid identifier name.)
