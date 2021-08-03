$NetBSD: patch-src_3rdparty_chromium_third__party_flatbuffers_src_src_util.cpp,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/flatbuffers/src/src/util.cpp.orig	2020-07-15 19:01:33.000000000 +0000
+++ src/3rdparty/chromium/third_party/flatbuffers/src/src/util.cpp
@@ -16,7 +16,7 @@
 
 // clang-format off
 // Dont't remove `format off`, it prevent reordering of win-includes.
-#define _POSIX_C_SOURCE 200112L // For stat from stat/stat.h and fseeko() (POSIX extensions).
+//#define _POSIX_C_SOURCE 200112L // For stat from stat/stat.h and fseeko() (POSIX extensions).
 #ifdef _WIN32
 #  ifndef WIN32_LEAN_AND_MEAN
 #    define WIN32_LEAN_AND_MEAN
@@ -32,7 +32,7 @@
 #  include <winbase.h>
 #  undef interface  // This is also important because of reasons
 #else
-#  define _XOPEN_SOURCE 600 // For PATH_MAX from limits.h (SUSv2 extension) 
+//#  define _XOPEN_SOURCE 600 // For PATH_MAX from limits.h (SUSv2 extension) 
 #  include <limits.h>
 #endif
 // clang-format on
