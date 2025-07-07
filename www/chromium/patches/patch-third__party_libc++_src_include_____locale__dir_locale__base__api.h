$NetBSD: patch-third__party_libc++_src_include_____locale__dir_locale__base__api.h,v 1.2 2025/07/07 09:23:37 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/libc++/src/include/__locale_dir/locale_base_api.h.orig	2025-06-30 06:54:11.000000000 +0000
+++ third_party/libc++/src/include/__locale_dir/locale_base_api.h
@@ -115,7 +115,7 @@
 
 #  if defined(__APPLE__)
 #    include <__locale_dir/support/apple.h>
-#  elif defined(__FreeBSD__)
+#  elif defined(__FreeBSD__) || defined(__NetBSD__)
 #    include <__locale_dir/support/freebsd.h>
 #  elif defined(_LIBCPP_MSVCRT_LIKE)
 #    include <__locale_dir/support/windows.h>
