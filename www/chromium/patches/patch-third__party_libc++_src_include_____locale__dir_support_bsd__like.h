$NetBSD: patch-third__party_libc++_src_include_____locale__dir_support_bsd__like.h,v 1.6 2025/09/12 16:02:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/libc++/src/include/__locale_dir/support/bsd_like.h.orig	2025-09-08 23:21:33.000000000 +0000
+++ third_party/libc++/src/include/__locale_dir/support/bsd_like.h
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
