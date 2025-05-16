$NetBSD: patch-tools_json__schema__compiler_cpp__bundle__generator.py,v 1.2 2025/05/16 16:08:33 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- tools/json_schema_compiler/cpp_bundle_generator.py.orig	2025-05-05 19:21:24.000000000 +0000
+++ tools/json_schema_compiler/cpp_bundle_generator.py
@@ -140,7 +140,7 @@ class CppBundleGenerator(object):
       elif platform == Platforms.FUCHSIA:
         ifdefs.append('BUILDFLAG(IS_FUCHSIA)')
       elif platform == Platforms.LINUX:
-        ifdefs.append('BUILDFLAG(IS_LINUX)')
+        ifdefs.append('BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)')
       elif platform == Platforms.MAC:
         ifdefs.append('BUILDFLAG(IS_MAC)')
       elif platform == Platforms.WIN:
