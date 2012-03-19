$NetBSD: patch-mozilla_xpcom_idl-parser_header.py,v 1.3 2012/03/19 10:36:00 ryoon Exp $

--- mozilla/xpcom/idl-parser/header.py.orig	2012-03-13 05:33:19.000000000 +0000
+++ mozilla/xpcom/idl-parser/header.py
@@ -527,6 +527,12 @@ if __name__ == '__main__':
         outfd.close()
 
     if options.depfile is not None:
+        dirname = os.path.dirname(options.depfile)
+        if dirname:
+            try:
+                os.makedirs(dirname)
+            except:
+                pass
         depfd = open(options.depfile, 'w')
         deps = [dep.replace('\\', '/') for dep in idl.deps]
 
