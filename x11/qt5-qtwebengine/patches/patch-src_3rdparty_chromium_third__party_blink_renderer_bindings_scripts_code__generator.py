$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_bindings_scripts_code__generator.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/code_generator.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/code_generator.py
@@ -13,6 +13,7 @@ import re
 import sys
 
 from idl_types import set_ancestors, IdlType
+from itertools import groupby
 from v8_globals import includes
 from v8_interface import constant_filters
 from v8_types import set_component_dirs
@@ -43,6 +44,7 @@ TEMPLATES_DIR = os.path.normpath(
 # after path[0] == invoking script dir
 sys.path.insert(1, THIRD_PARTY_DIR)
 import jinja2
+from jinja2.filters import make_attrgetter, environmentfilter
 
 
 def generate_indented_conditional(code, conditional):
@@ -88,6 +90,13 @@ def runtime_enabled_if(code, name):
     return generate_indented_conditional(code, function)
 
 
+@environmentfilter
+def do_stringify_key_group_by(environment, value, attribute):
+    expr = make_attrgetter(environment, attribute)
+    key = lambda item: '' if expr(item) is None else str(expr(item))
+    return groupby(sorted(value, key=key), expr)
+
+
 def initialize_jinja_env(cache_dir):
     jinja_env = jinja2.Environment(
         loader=jinja2.FileSystemLoader(TEMPLATES_DIR),
@@ -117,6 +126,7 @@ def initialize_jinja_env(cache_dir):
     })
     jinja_env.filters.update(constant_filters())
     jinja_env.filters.update(method_filters())
+    jinja_env.filters["stringifykeygroupby"] = do_stringify_key_group_by
     return jinja_env
 
 
