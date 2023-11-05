$NetBSD: patch-versioneer.py,v 1.1 2023/11/05 20:25:22 wiz Exp $

Fix build with Python 3.12.

--- versioneer.py.orig	2019-04-25 15:59:49.000000000 +0000
+++ versioneer.py
@@ -409,9 +409,9 @@ def get_config_from_root(root):
     # configparser.NoOptionError (if it lacks "VCS="). See the docstring at
     # the top of versioneer.py for instructions on writing your setup.cfg .
     setup_cfg = os.path.join(root, "setup.cfg")
-    parser = configparser.SafeConfigParser()
+    parser = configparser.ConfigParser()
     with open(setup_cfg, "r") as f:
-        parser.readfp(f)
+        parser.read_file(f)
     VCS = parser.get("versioneer", "VCS")  # mandatory
 
     def get(parser, name):
