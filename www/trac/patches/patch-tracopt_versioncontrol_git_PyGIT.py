$NetBSD: patch-tracopt_versioncontrol_git_PyGIT.py,v 1.2 2015/01/18 14:46:09 gdt Exp $

The git browser can fail if the git log process has already exited when
trac tries to terminate it (resulting in a python exception).

This patch should be applied upstream; Reported to trac-devel@ on
2014-03-11 and on 2015-01-18.

--- tracopt/versioncontrol/git/PyGIT.py.orig	2013-02-01 00:47:41.000000000 +0000
+++ tracopt/versioncontrol/git/PyGIT.py
@@ -913,7 +913,11 @@ class Storage(object):
                         except ValueError:
                             break
             f.close()
-            terminate(p[0])
+            # The process may or may not have finished.
+            try:
+                terminate(p[0])
+            except:
+                pass
             p[0].wait()
             p[:] = []
             while True:
@@ -930,7 +934,10 @@ class Storage(object):
 
         if p:
             p[0].stdout.close()
-            terminate(p[0])
+            try:
+                terminate(p[0])
+            except:
+                pass
             p[0].wait()
 
     def last_change(self, sha, path, historian=None):
