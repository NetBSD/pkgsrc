$NetBSD: patch-src_3rdparty_chromium_tools_gritsettings_resource__ids.spec,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3 (remove catapult)

--- src/3rdparty/chromium/tools/gritsettings/resource_ids.spec.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/tools/gritsettings/resource_ids.spec
@@ -499,12 +499,6 @@
   "content/shell/shell_resources.grd": {
     "includes": [2940],
   },
-
-  # This file is generated during the build.
-  "<(SHARED_INTERMEDIATE_DIR)/content/browser/tracing/tracing_resources.grd": {
-    "META": {"sizes": {"includes": [20],}},
-    "includes": [2960],
-  },
   # END content/ section.
 
   # START ios/web/ section.
