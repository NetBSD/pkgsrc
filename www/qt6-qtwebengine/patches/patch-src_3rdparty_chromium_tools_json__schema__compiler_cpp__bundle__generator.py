$NetBSD: patch-src_3rdparty_chromium_tools_json__schema__compiler_cpp__bundle__generator.py,v 1.1 2025/12/21 09:38:46 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/tools/json_schema_compiler/cpp_bundle_generator.py.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/tools/json_schema_compiler/cpp_bundle_generator.py
@@ -145,7 +145,7 @@ class CppBundleGenerator(object):
         # BUILDFLAG(IS_CHROMEOS) && BUILDFLAG(IS_CHROMEOS_LACROS).
         ifdefs.append('BUILDFLAG(IS_CHROMEOS_LACROS)')
       elif platform == Platforms.LINUX:
-        ifdefs.append('BUILDFLAG(IS_LINUX)')
+        ifdefs.append('BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)')
       elif platform == Platforms.MAC:
         ifdefs.append('BUILDFLAG(IS_MAC)')
       elif platform == Platforms.WIN:
