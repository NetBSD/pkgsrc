$NetBSD: patch-robobrowser_helpers.py,v 1.2 2018/10/12 23:17:34 leot Exp $

Add support for Python 3.7.

--- robobrowser/helpers.py.orig	2015-06-07 19:27:41.000000000 +0000
+++ robobrowser/helpers.py
@@ -3,6 +3,10 @@ Miscellaneous helper functions
 """
 
 import re
+try:
+    re._pattern_type
+except AttributeError:
+    re._pattern_type = re.Pattern
 
 from bs4 import BeautifulSoup
 from bs4.element import Tag
