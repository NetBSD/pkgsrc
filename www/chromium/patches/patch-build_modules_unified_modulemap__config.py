$NetBSD: patch-build_modules_unified_modulemap__config.py,v 1.12 2026/11/19 19:45:51 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- build/modules/unified/modulemap_config.py.orig	2026-11-11 21:01:38.000000000 +0000
+++ build/modules/unified/modulemap_config.py
@@ -62,7 +62,7 @@ class AllowedHeader(Header):
 
 
 def headers(os):
-    is_linux = os == 'linux'  # noqa: F841
+    is_linux = os == 'linux' or os == 'openbsd' or os == 'freebsd' or os == 'netbsd'  # noqa: F841
     is_android = os == 'android'
     is_ios = os == 'ios'  # noqa: F841
     is_mac = os == 'mac'  # noqa: F841
