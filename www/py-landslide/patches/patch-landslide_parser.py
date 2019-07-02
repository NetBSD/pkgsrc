$NetBSD: patch-landslide_parser.py,v 1.1 2019/07/02 04:19:59 adam Exp $

Fix for py-markdown >= 3.0.0
https://github.com/adamzap/landslide/pull/211

--- landslide/parser.py.orig	2015-03-12 03:47:59.000000000 +0000
+++ landslide/parser.py
@@ -58,7 +58,7 @@ class Parser(object):
             if text.startswith(u'\ufeff'):  # check for unicode BOM
                 text = text[1:]
 
-            return markdown.markdown(text, self.md_extensions)
+            return markdown.markdown(text, extensions=self.md_extensions)
         elif self.format == 'restructuredtext':
             try:
                 from landslide.rst import html_body
