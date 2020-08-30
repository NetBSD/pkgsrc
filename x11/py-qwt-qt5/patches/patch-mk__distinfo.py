$NetBSD: patch-mk__distinfo.py,v 1.1 2020/08/30 08:21:15 tnn Exp $

Work around DESTDIR installation issue

--- mk_distinfo.py.orig	2019-02-23 12:55:34.000000000 +0000
+++ mk_distinfo.py
@@ -98,6 +98,11 @@ for name in installed:
         else:
             fn_name = fn
 
+        if (fn.startswith(sys.prefix + "/")):
+            fn = os.environ.get("DESTDIR") + fn
+        if (os.path.isdir(fn)):
+            continue
+
         fn_f = open(fn, 'rb')
         data = fn_f.read()
         fn_f.close()
