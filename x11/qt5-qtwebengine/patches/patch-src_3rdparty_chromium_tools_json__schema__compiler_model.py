$NetBSD: patch-src_3rdparty_chromium_tools_json__schema__compiler_model.py,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/tools/json_schema_compiler/model.py.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/tools/json_schema_compiler/model.py
@@ -676,7 +676,7 @@ class Platforms(object):
   CHROMEOS = _PlatformInfo("chromeos")
   CHROMEOS_TOUCH = _PlatformInfo("chromeos_touch")
   LACROS = _PlatformInfo("lacros")
-  LINUX = _PlatformInfo("linux")
+  LINUX = _PlatformInfo("linux") or _PlatformInfo("bsd")
   MAC = _PlatformInfo("mac")
   WIN = _PlatformInfo("win")
 
