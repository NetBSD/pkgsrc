$NetBSD: patch-src_3rdparty_chromium_third__party_libc++_src_src_chrono.cpp,v 1.1 2025/12/21 09:38:42 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/libc++/src/src/chrono.cpp.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/third_party/libc++/src/src/chrono.cpp
@@ -33,7 +33,7 @@
 
 // OpenBSD and GPU do not have a fully conformant suite of POSIX timers, but
 // it does have clock_gettime and CLOCK_MONOTONIC which is all we need.
-#if defined(__APPLE__) || defined(__gnu_hurd__) || defined(__OpenBSD__) || defined(__AMDGPU__) ||                      \
+#if defined(__APPLE__) || defined(__gnu_hurd__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__AMDGPU__) ||                      \
     defined(__NVPTX__) || (defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0)
 #  define _LIBCPP_HAS_CLOCK_GETTIME
 #endif
