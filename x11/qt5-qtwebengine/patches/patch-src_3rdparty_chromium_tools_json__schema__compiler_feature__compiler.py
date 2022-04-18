$NetBSD: patch-src_3rdparty_chromium_tools_json__schema__compiler_feature__compiler.py,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/tools/json_schema_compiler/feature_compiler.py.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/tools/json_schema_compiler/feature_compiler.py
@@ -245,6 +245,8 @@ FEATURE_GRAMMAR = ({
                 'linux': 'Feature::LINUX_PLATFORM',
                 'mac': 'Feature::MACOSX_PLATFORM',
                 'win': 'Feature::WIN_PLATFORM',
+                'bsd': 'Feature::LINUX_PLATFORM',
+                'netbsd': 'Feature::LINUX_PLATFORM',
             }
         }
     },
