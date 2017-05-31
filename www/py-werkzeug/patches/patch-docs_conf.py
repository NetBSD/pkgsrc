$NetBSD: patch-docs_conf.py,v 1.1 2017/05/31 08:24:38 adam Exp $

Skip missing Werkzeug theme.

--- docs/conf.py.orig	2017-05-31 07:56:02.000000000 +0000
+++ docs/conf.py
@@ -95,7 +95,7 @@ add_function_parentheses = True
 #show_authors = False
 
 # The name of the Pygments (syntax highlighting) style to use.
-pygments_style = 'werkzeug_theme_support.WerkzeugStyle'
+#pygments_style = 'werkzeug_theme_support.WerkzeugStyle'
 
 # doctest setup code
 doctest_global_setup = '''\
@@ -106,8 +106,8 @@ from werkzeug import *
 # Options for HTML output
 # -----------------------
 
-html_theme = 'werkzeug'
-html_theme_path = ['_themes']
+#html_theme = 'werkzeug'
+#html_theme_path = ['_themes']
 
 # The name for this set of Sphinx documents.  If None, it defaults to
 # "<project> v<release> documentation".
