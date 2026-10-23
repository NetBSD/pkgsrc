$NetBSD: patch-tools_json__schema__compiler_feature__compiler.py,v 1.31 2026/10/23 15:05:36 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- tools/json_schema_compiler/feature_compiler.py.orig	2026-10-19 20:07:21.000000000 +0000
+++ tools/json_schema_compiler/feature_compiler.py
@@ -251,6 +251,9 @@ FEATURE_GRAMMAR = {
         'linux': 'Feature::LINUX_PLATFORM',
         'mac': 'Feature::MACOSX_PLATFORM',
         'win': 'Feature::WIN_PLATFORM',
+        'openbsd': 'Feature::LINUX_PLATFORM',
+        'freebsd': 'Feature::LINUX_PLATFORM',
+        'netbsd': 'Feature::LINUX_PLATFORM',
       }
     }
   },
