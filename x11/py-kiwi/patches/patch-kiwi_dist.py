$NetBSD: patch-kiwi_dist.py,v 1.1 2014/01/10 14:43:36 jperkin Exp $

Use PKGLOCALEDIR.

--- kiwi/dist.py.orig	2011-06-10 14:35:59.000000000 +0000
+++ kiwi/dist.py
@@ -259,7 +259,7 @@ def compile_po_files(domain, dirname='lo
             info('compiling %s -> %s' % (po, mo))
             if os.system(cmd) != 0:
                 raise SystemExit("Error while running msgfmt")
-        dest = os.path.dirname(os.path.join('share', mo))
+        dest = os.path.dirname(os.path.join('@PKGLOCALEDIR@', mo))
         data_files.append((dest, [mo]))
 
     return data_files
