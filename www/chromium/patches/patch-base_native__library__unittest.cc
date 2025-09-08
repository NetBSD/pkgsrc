$NetBSD: patch-base_native__library__unittest.cc,v 1.6 2025/09/08 13:24:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/native_library_unittest.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ base/native_library_unittest.cc
@@ -135,7 +135,7 @@ TEST(NativeLibraryTest, LoadLibrary) {
 // versions with respect to symbol resolution scope.
 // TSan and MSan error out on RTLD_DEEPBIND, https://crbug.com/705255
 #if !BUILDFLAG(IS_ANDROID) && !defined(THREAD_SANITIZER) && \
-    !defined(MEMORY_SANITIZER)
+    !defined(MEMORY_SANITIZER) && !BUILDFLAG(IS_BSD)
 
 // Verifies that the |prefer_own_symbols| option satisfies its guarantee that
 // a loaded library will always prefer local symbol resolution before
