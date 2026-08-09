$NetBSD: patch-build_modules_unified_modulemap__config.py,v 1.3 2026/08/09 06:31:07 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- build/modules/unified/modulemap_config.py.orig	2026-08-05 20:17:42.000000000 +0000
+++ build/modules/unified/modulemap_config.py
@@ -57,7 +57,7 @@ class AllowedHeader(Header):
 
 
 def headers(os):
-  is_linux = os == 'linux'
+  is_linux = os == 'linux' or os == 'openbsd' or os == 'freebsd' or os == 'netbsd'
   is_android = os == 'android'
   is_ios = os == 'ios'
   is_mac = os == 'mac'
