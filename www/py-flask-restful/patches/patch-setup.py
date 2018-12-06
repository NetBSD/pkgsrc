$NetBSD: patch-setup.py,v 1.1 2018/12/06 19:32:05 adam Exp $

Prefer pycryptodome.

--- setup.py.orig	2018-12-06 12:01:18.000000000 +0000
+++ setup.py
@@ -60,7 +60,7 @@ setup(
     tests_require=['Flask-RESTful[paging]', 'mock>=0.8', 'blinker'],
     # Install these with "pip install -e '.[paging]'" or '.[docs]'
     extras_require={
-        'paging': 'pycrypto>=2.6',
+        'paging': 'pycryptodome',
         'docs': 'sphinx',
     }
 )
