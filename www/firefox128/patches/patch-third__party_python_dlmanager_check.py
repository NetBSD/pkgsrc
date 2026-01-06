$NetBSD: patch-third__party_python_dlmanager_check.py,v 1.1 2026/01/06 16:16:39 ryoon Exp $

--- third_party/python/dlmanager/check.py.orig	2025-08-11 17:07:30.000000000 +0000
+++ third_party/python/dlmanager/check.py
@@ -5,7 +5,7 @@ import argparse
 
 import os
 import argparse
-import pipes
+import shlex
 import shutil
 import tempfile
 
@@ -23,7 +23,7 @@ def run(cmd, **kwargs):
 
 
 def run(cmd, **kwargs):
-    msg = 'Running: |%s|' % ' '.join(pipes.quote(c) for c in cmd)
+    msg = 'Running: |%s|' % ' '.join(shlex.quote(c) for c in cmd)
     if kwargs.get('cwd'):
         msg += ' in %s' % kwargs['cwd']
     print(msg)
