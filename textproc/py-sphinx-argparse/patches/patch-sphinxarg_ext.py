$NetBSD: patch-sphinxarg_ext.py,v 1.1 2025/12/28 21:23:36 wiz Exp $

Work around sphinx 9 compatibility problem.
https://github.com/sphinx-doc/sphinx/issues/14206

--- sphinxarg/ext.py.orig	2025-12-28 19:31:54.689028452 +0000
+++ sphinxarg/ext.py
@@ -11,7 +11,7 @@ from docutils.frontend import get_defaul
 from docutils.parsers.rst import Parser
 from docutils.parsers.rst.directives import flag, unchanged
 from docutils.statemachine import StringList
-from sphinx.ext.autodoc import mock
+from sphinx.ext.autodoc._dynamic._mock import mock
 from sphinx.util.docutils import SphinxDirective, new_document
 from sphinx.util.nodes import nested_parse_with_titles
 
