$NetBSD: patch-src_landslide_parser.py,v 1.1 2019/05/11 22:09:21 kamil Exp $

Cherry pick support for `markdown` v3.0+

 - https://github.com/adamzap/landslide/commit/e4005a418f851314ce272fbc8cb5f5e3100568ed

--- src/landslide/parser.py.orig	2015-03-12 03:47:59.000000000 +0000
+++ src/landslide/parser.py
@@ -58,7 +58,7 @@ class Parser(object):
             if text.startswith(u'\ufeff'):  # check for unicode BOM
                 text = text[1:]
 
-            return markdown.markdown(text, self.md_extensions)
+            return markdown.markdown(text, extensions=self.md_extensions)
         elif self.format == 'restructuredtext':
             try:
                 from landslide.rst import html_body
