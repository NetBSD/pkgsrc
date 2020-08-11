$NetBSD: patch-setup.py,v 1.1 2020/08/11 18:43:20 joerg Exp $

--- setup.py.orig	2020-06-17 13:28:07.000000000 +0000
+++ setup.py
@@ -8,7 +8,7 @@ version_ns = {}
 with open(os.path.join(HERE, NAME, '__version__.py')) as f:
     exec(f.read(), {}, version_ns)
 
-with open(os.path.join(HERE, 'README.md')) as f:
+with open(os.path.join(HERE, 'README.md'), **({'encoding': 'UTF-8'} if sys.version_info.major>=3 else {})) as f:
     long_description = f.read()
 
 setup(
