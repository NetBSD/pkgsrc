$NetBSD: patch-MoinMoin_support_werkzeug_templates.py,v 1.1 2012/01/27 05:52:40 obache Exp $

fix for python 2.7
 * http://hg.moinmo.in/moin/1.9/rev/a4a7f275b7b3

--- MoinMoin/support/werkzeug/templates.py.orig	2010-06-26 21:46:44.000000000 +0000
+++ MoinMoin/support/werkzeug/templates.py
@@ -12,7 +12,6 @@ import sys
 import re
 import __builtin__ as builtins
 from compiler import ast, parse
-from compiler.consts import SC_LOCAL, SC_GLOBAL, SC_FREE, SC_CELL
 from compiler.pycodegen import ModuleCodeGenerator
 from tokenize import PseudoToken
 from werkzeug import utils
