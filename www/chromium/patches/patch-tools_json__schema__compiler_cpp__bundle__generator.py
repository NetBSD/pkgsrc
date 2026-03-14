$NetBSD: patch-tools_json__schema__compiler_cpp__bundle__generator.py,v 1.16 2026/03/14 12:40:43 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- tools/json_schema_compiler/cpp_bundle_generator.py.orig	2026-03-11 22:12:25.000000000 +0000
+++ tools/json_schema_compiler/cpp_bundle_generator.py
@@ -140,7 +140,7 @@ class CppBundleGenerator(object):
       elif platform == Platforms.DESKTOP_ANDROID:
         ifdefs.append('BUILDFLAG(IS_DESKTOP_ANDROID)')
       elif platform == Platforms.LINUX:
-        ifdefs.append('BUILDFLAG(IS_LINUX)')
+        ifdefs.append('BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)')
       elif platform == Platforms.MAC:
         ifdefs.append('BUILDFLAG(IS_MAC)')
       elif platform == Platforms.WIN:
