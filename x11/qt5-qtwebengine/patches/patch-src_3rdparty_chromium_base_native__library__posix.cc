$NetBSD: patch-src_3rdparty_chromium_base_native__library__posix.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/native_library_posix.cc.orig	2020-06-25 09:31:18.000000000 +0000
+++ src/3rdparty/chromium/base/native_library_posix.cc
@@ -29,7 +29,7 @@ NativeLibrary LoadNativeLibraryWithOptio
   // http://crbug.com/17943, http://crbug.com/17557, http://crbug.com/36892,
   // and http://crbug.com/40794.
   int flags = RTLD_LAZY;
-#if defined(OS_ANDROID) || !defined(RTLD_DEEPBIND)
+#if defined(OS_ANDROID) || !defined(RTLD_DEEPBIND) || defined(OS_BSD)
   // Certain platforms don't define RTLD_DEEPBIND. Android dlopen() requires
   // further investigation, as it might vary across versions. Crash here to
   // warn developers that they're trying to rely on uncertain behavior.
