$NetBSD: patch-tools_json__schema__compiler_feature__compiler.py,v 1.15 2026/02/15 09:04:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- tools/json_schema_compiler/feature_compiler.py.orig	2026-02-03 22:07:10.000000000 +0000
+++ tools/json_schema_compiler/feature_compiler.py
@@ -289,6 +289,9 @@ FEATURE_GRAMMAR = ({
                 'linux': 'Feature::LINUX_PLATFORM',
                 'mac': 'Feature::MACOSX_PLATFORM',
                 'win': 'Feature::WIN_PLATFORM',
+                'openbsd': 'Feature::LINUX_PLATFORM',
+                'freebsd': 'Feature::LINUX_PLATFORM',
+                'netbsd': 'Feature::LINUX_PLATFORM',
             }
         }
     },
