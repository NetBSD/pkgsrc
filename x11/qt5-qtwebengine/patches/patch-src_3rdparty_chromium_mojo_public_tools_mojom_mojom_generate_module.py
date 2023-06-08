$NetBSD: patch-src_3rdparty_chromium_mojo_public_tools_mojom_mojom_generate_module.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/mojo/public/tools/mojom/mojom/generate/module.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/mojo/public/tools/mojom/mojom/generate/module.py
@@ -398,7 +398,8 @@ class Field(object):
 
 
 class StructField(Field):
-  pass
+  def __hash__(self):
+    return super(Field, self).__hash__()
 
 
 class UnionField(Field):
