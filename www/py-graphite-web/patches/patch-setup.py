$NetBSD: patch-setup.py,v 1.1 2015/12/11 21:45:07 riz Exp $

Use proper paths for storage and config example files.

--- setup.py.orig	2015-11-27 10:37:16.000000000 -0800
+++ setup.py	2015-12-04 14:33:20.000000000 -0800
@@ -41,11 +41,11 @@
 storage_dirs = []
 
 for subdir in ('whisper', 'rrd', 'log', 'log/webapp'):
-  storage_dirs.append( ('storage/%s' % subdir, []) )
+  storage_dirs.append( ('@GRAPHITE_DIR@/%s' % subdir, []) )
 
 webapp_content = {}
 
-for root, dirs, files in os.walk('webapp/content'):
+for root, dirs, files in os.walk('graphite/webapp/content'):
   for filename in files:
     filepath = os.path.join(root, filename)
 
@@ -55,8 +55,8 @@
     webapp_content[root].append(filepath)
 
 
-conf_files = [ ('conf', glob('conf/*.example')) ]
-examples = [ ('examples', glob('examples/example-*')) ]
+conf_files = [ ('@PREFIX@/@GRAPHITE_EGDIR@', glob('conf/*.example')) ]
+examples = [ ('@PREFIX@/@GRAPHITE_EGDIR@', glob('examples/example-*')) ]
 
 try:
     setup(
