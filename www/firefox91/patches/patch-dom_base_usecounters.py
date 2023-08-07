$NetBSD: patch-dom_base_usecounters.py,v 1.1 2023/08/07 13:28:04 abs Exp $

Update for modern (>3.9) python open() mode

--- dom/base/usecounters.py.orig	2022-08-15 18:04:32.000000000 +0000
+++ dom/base/usecounters.py
@@ -8,7 +8,7 @@ import re
 
 def read_conf(conf_filename):
     # Can't read/write from a single StringIO, so make a new one for reading.
-    stream = open(conf_filename, "rU")
+    stream = open(conf_filename, "r")
 
     def parse_counters(stream):
         for line_num, line in enumerate(stream):
