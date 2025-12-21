$NetBSD: patch-src_3rdparty_chromium_tools_json__schema__compiler_feature__compiler.py,v 1.1 2025/12/21 09:38:46 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/tools/json_schema_compiler/feature_compiler.py.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/tools/json_schema_compiler/feature_compiler.py
@@ -292,6 +292,9 @@ FEATURE_GRAMMAR = ({
                 'linux': 'Feature::LINUX_PLATFORM',
                 'mac': 'Feature::MACOSX_PLATFORM',
                 'win': 'Feature::WIN_PLATFORM',
+                'openbsd': 'Feature::LINUX_PLATFORM',
+                'freebsd': 'Feature::LINUX_PLATFORM',
+                'netbsd': 'Feature::LINUX_PLATFORM',
             }
         }
     },
