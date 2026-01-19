$NetBSD: patch-third__party_libc++_src_src_chrono.cpp,v 1.14 2026/01/19 16:14:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/libc++/src/src/chrono.cpp.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/libc++/src/src/chrono.cpp
@@ -38,7 +38,7 @@
 // OpenBSD and GPU do not have a fully conformant suite of POSIX timers, but
 // it does have clock_gettime and CLOCK_MONOTONIC which is all we need.
 #if defined(__APPLE__) || defined(__gnu_hurd__) || defined(__OpenBSD__) || defined(__AMDGPU__) ||                      \
-    defined(__NVPTX__) || (defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0)
+    defined(__NVPTX__) || (defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0) || defined(__FreeBSD__) || defined(__NetBSD__)
 #  define _LIBCPP_HAS_CLOCK_GETTIME
 #endif
 
