$NetBSD: patch-setup.py,v 1.1 2017/10/27 15:47:31 adam Exp $

dnspython3 has been superseded by the regular dnspython

--- setup.py.orig	2017-10-27 15:37:17.000000000 +0000
+++ setup.py
@@ -14,8 +14,7 @@ version = '1.3.1'
 if not '2.6' <= sys.version < '3.0' and not '3.2' <= sys.version:
     raise ImportError('Python version not supported')
 
-tests_require = ['nose', 'pycountry',
-    'dnspython' if sys.version < '3.0' else 'dnspython3']
+tests_require = ['nose', 'pycountry', 'dnspython']
 
 doctests = ['docs/htmlfill.txt', 'docs/Validator.txt',
     'formencode/tests/non_empty.txt']
