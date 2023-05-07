$NetBSD: patch-docs_conf.py,v 1.1 2023/05/07 12:41:15 wiz Exp $

Sphinx compat per https://github.com/sphinx-doc/sphinx/issues/11094

--- docs/conf.py.orig	2023-05-07 12:40:16.145775205 +0000
+++ docs/conf.py
@@ -28,7 +28,7 @@ rst_prolog = '''
 pygments_style = 'sphinx'
 
 extlinks = {
-    'pelican-doc':  ('https://docs.getpelican.com/%s/', '')
+    'pelican-doc':  ('https://docs.getpelican.com/%s/', '%s')
 }
 
 # -- Options for HTML output --------------------------------------------------
