$NetBSD: patch-src_3rdparty_chromium_tools_json__schema__compiler_cpp__bundle__generator.py,v 1.2 2026/04/30 06:39:44 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/tools/json_schema_compiler/cpp_bundle_generator.py.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/tools/json_schema_compiler/cpp_bundle_generator.py
@@ -140,7 +140,7 @@ class CppBundleGenerator(object):
       elif platform == Platforms.DESKTOP_ANDROID:
         ifdefs.append('BUILDFLAG(IS_DESKTOP_ANDROID)')
       elif platform == Platforms.LINUX:
-        ifdefs.append('BUILDFLAG(IS_LINUX)')
+        ifdefs.append('BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)')
       elif platform == Platforms.MAC:
         ifdefs.append('BUILDFLAG(IS_MAC)')
       elif platform == Platforms.WIN:
