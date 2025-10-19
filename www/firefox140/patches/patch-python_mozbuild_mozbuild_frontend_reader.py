$NetBSD: patch-python_mozbuild_mozbuild_frontend_reader.py,v 1.1 2025/10/19 11:56:56 leot Exp $

* For Python 3.14 too.

--- python/mozbuild/mozbuild/frontend/reader.py.orig	2025-10-08 15:23:09.699830974 +0000
+++ python/mozbuild/mozbuild/frontend/reader.py
@@ -470,7 +470,7 @@ class TemplateFunction:
             return c(
                 ast.Subscript(
                     value=c(ast.Name(id=self._global_name, ctx=ast.Load())),
-                    slice=c(ast.Index(value=c(ast.Str(s=node.id)))),
+                    slice=c(ast.Index(value=c(ast.Constant(value=node.id)))),
                     ctx=node.ctx,
                 )
             )
