$NetBSD: patch-Pyblosxom_plugins_readmore.py,v 1.2 2019/05/07 14:26:06 hauke Exp $

Try to make sure the truncated text is valid HTML

Use the current flavour before the default one, if available.

--- Pyblosxom/plugins/readmore.py.orig	2013-07-31 00:53:58.000000000 +0000
+++ Pyblosxom/plugins/readmore.py
@@ -194,8 +194,15 @@ def cb_story(args):
     breakpoint = config.get("readmore_breakpoint", READMORE_BREAKPOINT)
     template = config.get("readmore_template", READMORE_TEMPLATE)
 
-    # check to see if the breakpoint is in the body.
-    match = re.search(breakpoint, entry["body"])
+    """
+    Check to see if the breakpoint is in the body.
+
+    Since it might have been wrapped in html tags by a markdown
+    plugin, grab everything from the end of breakpoint up to, but
+    excluding, either the first opening tag, or newline.
+    """
+    match = re.search('(' + breakpoint + ')(.*?)(<[ ]*?[^/].+|[\n])',
+                      entry["body"])
 
     # if not, return because we don't have to do anything
     if not match:
@@ -209,7 +216,11 @@ def cb_story(args):
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
@@ -218,4 +229,4 @@ def cb_story(args):
                         "flavour": flavour})
 
     entry["just_summary"] = 1
-    entry["body"] = entry["body"][:match.start()] + link
+    entry["body"] = entry["body"][:match.start(1)] + link + str(match.group(2))
