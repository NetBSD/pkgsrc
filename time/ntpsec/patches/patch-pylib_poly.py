$NetBSD: patch-pylib_poly.py,v 1.1 2019/03/25 15:40:35 tnn Exp $

- NetBSD fix from upstream:
  https://gitlab.com/NTPsec/ntpsec/commit/a4453ee5a4edf87cf081fe69f5c214a8b2a82b58

--- pylib/poly.py.orig	2019-01-14 05:40:59.000000000 +0000
+++ pylib/poly.py
@@ -103,9 +103,9 @@ else:  # Python 3
                                 newline="\n", line_buffering=True)
 
     # This is the one situation where we *can* force unicode.
-    if "UTF-8" != sys.stdout.encoding:
+    if "utf-8" != sys.stdout.encoding.lower():
         forced_utf8 = True
         sys.stdout = make_std_wrapper(sys.stdout)
-    if "UTF-8" != sys.stderr.encoding:
+    if "utf-8" != sys.stderr.encoding.lower():
         forced_utf8 = True
         sys.stderr = make_std_wrapper(sys.stderr)
