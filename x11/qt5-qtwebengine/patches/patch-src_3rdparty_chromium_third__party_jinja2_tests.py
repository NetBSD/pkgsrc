$NetBSD: patch-src_3rdparty_chromium_third__party_jinja2_tests.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/jinja2/tests.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/jinja2/tests.py
@@ -10,7 +10,7 @@
 """
 import operator
 import re
-from collections import Mapping
+from collections.abc import Mapping
 from jinja2.runtime import Undefined
 from jinja2._compat import text_type, string_types, integer_types
 import decimal
