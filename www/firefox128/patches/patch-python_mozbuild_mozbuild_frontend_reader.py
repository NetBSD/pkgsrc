$NetBSD: patch-python_mozbuild_mozbuild_frontend_reader.py,v 1.1 2026/01/06 16:16:39 ryoon Exp $

--- python/mozbuild/mozbuild/frontend/reader.py.orig	2025-08-11 17:07:23.000000000 +0000
+++ python/mozbuild/mozbuild/frontend/reader.py
@@ -470,7 +470,7 @@ class TemplateFunction(object):
             return c(
                 ast.Subscript(
                     value=c(ast.Name(id=self._global_name, ctx=ast.Load())),
-                    slice=c(ast.Index(value=c(ast.Str(s=node.id)))),
+                    slice=c(ast.Index(value=c(ast.Constant(value=node.id)))),
                     ctx=node.ctx,
                 )
             )
