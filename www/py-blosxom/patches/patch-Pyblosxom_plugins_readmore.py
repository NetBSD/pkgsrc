$NetBSD: patch-Pyblosxom_plugins_readmore.py,v 1.1 2015/05/22 14:01:16 hauke Exp $

Use the current flavour before the default one, if available.

--- Pyblosxom/plugins/readmore.py.orig	2013-07-31 00:53:58.000000000 +0000
+++ Pyblosxom/plugins/readmore.py
@@ -209,7 +209,11 @@ def cb_story(args):
     # otherwise we replace the breakpoint with the template
     base_url = config["base_url"]
     file_path = entry["file_path"]
-    flavour = config.get("default_flavour", "html")
+
+    # Set and use current (or default) flavour for full entry
+    flavour = data.get(
+        "flavour", config.get("default_flavour", "html"))
+    
     url = '%s/%s.%s' % (base_url, file_path, flavour)
 
     link = (template % {"url": url,
