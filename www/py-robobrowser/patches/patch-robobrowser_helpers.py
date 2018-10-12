$NetBSD: patch-robobrowser_helpers.py,v 1.1 2018/10/12 23:08:10 leot Exp $

Add support for Python 3.7.

--- robobrowser/helpers.py.orig	2015-06-07 19:27:41.000000000 +0000
+++ robobrowser/helpers.py
@@ -3,6 +3,7 @@ Miscellaneous helper functions
 """
 
 import re
+re._pattern_type = getattr(re, '_pattern_type', re.Pattern)
 
 from bs4 import BeautifulSoup
 from bs4.element import Tag
