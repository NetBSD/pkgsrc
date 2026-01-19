$NetBSD: patch-third__party_libc++_src_src_filesystem_filesystem__clock.cpp,v 1.14 2026/01/19 16:14:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/libc++/src/src/filesystem/filesystem_clock.cpp.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/libc++/src/src/filesystem/filesystem_clock.cpp
@@ -37,7 +37,7 @@
 #endif
 
 #if defined(__APPLE__) || defined(__gnu_hurd__) || defined(__AMDGPU__) || defined(__NVPTX__) ||                        \
-    (defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0)
+    (defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #  define _LIBCPP_HAS_CLOCK_GETTIME
 #endif
 
