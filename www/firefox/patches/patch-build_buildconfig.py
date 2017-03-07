$NetBSD: patch-build_buildconfig.py,v 1.1 2017/03/07 20:45:43 ryoon Exp $

--- build/buildconfig.py.orig	2016-09-19 16:19:29.000000000 +0000
+++ build/buildconfig.py
@@ -16,5 +16,5 @@ for var in ('topsrcdir', 'topobjdir', 'd
 substs = dict(substs)
 
 for var in os.environ:
-    if var != 'SHELL' and var in substs:
+    if var not in ('CPP', 'CXXCPP', 'SHELL') and var in substs:
         substs[var] = os.environ[var]
