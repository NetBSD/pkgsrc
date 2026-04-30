$NetBSD: patch-src_3rdparty_chromium_third__party_libc++_src_include_____locale__dir_support_bsd__like.h,v 1.1 2026/04/30 06:39:43 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/libc++/src/include/__locale_dir/support/bsd_like.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/third_party/libc++/src/include/__locale_dir/support/bsd_like.h
@@ -24,7 +24,11 @@
 #  include <wctype.h>
 #endif
 
+#if defined(__NetBSD__)
+#include <locale.h>
+#else
 #include <xlocale.h>
+#endif
 
 #if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
 #  pragma GCC system_header
