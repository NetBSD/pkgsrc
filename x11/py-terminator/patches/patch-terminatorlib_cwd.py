$NetBSD: patch-terminatorlib_cwd.py,v 1.1 2019/06/01 01:17:12 kamil Exp $

Use syntax of .cwd() that works, as_dict()['cwd'] faults.
Fixes terminator on NetBSD.

--- terminatorlib/cwd.py.orig	2019-06-01 01:01:46.535724473 +0000
+++ terminatorlib/cwd.py
@@ -82,6 +82,6 @@ def sunos_get_pid_cwd(pid):
 
 def psutil_cwd(pid):
     """Determine the cwd using psutil which also supports Darwin"""
-    return psutil.Process(pid).as_dict()['cwd']
+    return psutil.Process(pid).cwd()
 
 # vim: set expandtab ts=4 sw=4:
