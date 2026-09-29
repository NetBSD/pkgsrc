$NetBSD: patch-build_modules_unified_modulemap__config.py,v 1.6 2026/09/29 07:42:47 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- build/modules/unified/modulemap_config.py.orig	2026-09-22 00:09:16.000000000 +0000
+++ build/modules/unified/modulemap_config.py
@@ -62,7 +62,7 @@ class AllowedHeader(Header):
 
 
 def headers(os):
-    is_linux = os == 'linux'
+    is_linux = os == 'linux' or os == 'openbsd' or os == 'freebsd' or os == 'netbsd'
     is_android = os == 'android'
     is_ios = os == 'ios'
     is_mac = os == 'mac'
