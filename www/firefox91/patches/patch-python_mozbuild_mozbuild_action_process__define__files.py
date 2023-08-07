$NetBSD: patch-python_mozbuild_mozbuild_action_process__define__files.py,v 1.1 2023/08/07 13:28:04 abs Exp $

Update for modern (>3.9) python open() mode

--- python/mozbuild/mozbuild/action/process_define_files.py.orig	2022-08-15 18:05:05.000000000 +0000
+++ python/mozbuild/mozbuild/action/process_define_files.py
@@ -36,7 +36,7 @@ def process_define_file(output, input):
     ) and not config.substs.get("JS_STANDALONE"):
         config = PartialConfigEnvironment(mozpath.join(topobjdir, "js", "src"))
 
-    with open(path, "rU") as input:
+    with open(path, "r") as input:
         r = re.compile(
             "^\s*#\s*(?P<cmd>[a-z]+)(?:\s+(?P<name>\S+)(?:\s+(?P<value>\S+))?)?", re.U
         )
