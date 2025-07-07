$NetBSD: patch-base_native__library__posix.cc,v 1.3 2025/07/07 09:23:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/native_library_posix.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ base/native_library_posix.cc
@@ -34,7 +34,7 @@ NativeLibrary LoadNativeLibraryWithOptio
   // http://crbug.com/17943, http://crbug.com/17557, http://crbug.com/36892,
   // and http://crbug.com/40794.
   int flags = RTLD_LAZY;
-#if BUILDFLAG(IS_ANDROID) || !defined(RTLD_DEEPBIND)
+#if BUILDFLAG(IS_ANDROID) || !defined(RTLD_DEEPBIND) || BUILDFLAG(IS_BSD)
   // Certain platforms don't define RTLD_DEEPBIND. Android dlopen() requires
   // further investigation, as it might vary across versions. Crash here to
   // warn developers that they're trying to rely on uncertain behavior.
