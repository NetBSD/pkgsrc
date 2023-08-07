$NetBSD: patch-python_mozbuild_mozbuild_preprocessor.py,v 1.1 2023/08/07 13:28:04 abs Exp $

Update for modern (>3.9) python open() mode

--- python/mozbuild/mozbuild/preprocessor.py.orig	2022-08-15 18:04:56.000000000 +0000
+++ python/mozbuild/mozbuild/preprocessor.py
@@ -531,7 +531,7 @@ class Preprocessor:
 
         if args:
             for f in args:
-                with io.open(f, "rU", encoding="utf-8") as input:
+                with io.open(f, "r", encoding="utf-8") as input:
                     self.processFile(input=input, output=out)
             if depfile:
                 mk = Makefile()
@@ -860,7 +860,7 @@ class Preprocessor:
                     args = self.applyFilters(args)
                 if not os.path.isabs(args):
                     args = os.path.join(self.curdir, args)
-                args = io.open(args, "rU", encoding="utf-8")
+                args = io.open(args, "r", encoding="utf-8")
             except Preprocessor.Error:
                 raise
             except Exception:
@@ -914,7 +914,7 @@ class Preprocessor:
 def preprocess(includes=[sys.stdin], defines={}, output=sys.stdout, marker="#"):
     pp = Preprocessor(defines=defines, marker=marker)
     for f in includes:
-        with io.open(f, "rU", encoding="utf-8") as input:
+        with io.open(f, "r", encoding="utf-8") as input:
             pp.processFile(input=input, output=output)
     return pp.includes
 
