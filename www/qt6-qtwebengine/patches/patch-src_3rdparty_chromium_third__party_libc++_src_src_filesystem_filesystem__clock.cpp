$NetBSD: patch-src_3rdparty_chromium_third__party_libc++_src_src_filesystem_filesystem__clock.cpp,v 1.1 2025/12/21 09:38:42 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/libc++/src/src/filesystem/filesystem_clock.cpp.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/third_party/libc++/src/src/filesystem/filesystem_clock.cpp
@@ -30,7 +30,7 @@
 #endif
 
 #if defined(__APPLE__) || defined(__gnu_hurd__) || defined(__AMDGPU__) || defined(__NVPTX__) ||                        \
-    (defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0)
+    (defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #  define _LIBCPP_HAS_CLOCK_GETTIME
 #endif
 
