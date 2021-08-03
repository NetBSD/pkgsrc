$NetBSD: patch-src_3rdparty_chromium_tools_json__schema__compiler_model.py,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/tools/json_schema_compiler/model.py.orig	2020-07-15 18:56:33.000000000 +0000
+++ src/3rdparty/chromium/tools/json_schema_compiler/model.py
@@ -605,7 +605,7 @@ class Platforms(object):
   """
   CHROMEOS = _PlatformInfo("chromeos")
   CHROMEOS_TOUCH = _PlatformInfo("chromeos_touch")
-  LINUX = _PlatformInfo("linux")
+  LINUX = _PlatformInfo("linux") or _PlatformInfo("bsd")
   MAC = _PlatformInfo("mac")
   WIN = _PlatformInfo("win")
 
