$NetBSD: patch-setup.py,v 1.2 2017/12/14 13:18:07 adam Exp $

Relax requirements.

--- setup.py.orig	2017-12-11 18:59:44.000000000 +0000
+++ setup.py
@@ -60,19 +60,19 @@ tests_require = [
     'bottle',
     'celery>=2.5',
     'exam>=0.5.2',
-    'flake8==3.5.0',
+    'flake8>=3.5.0',
     'logbook',
     'mock',
     'nose',
     'pycodestyle',
     'pytz',
     'pytest>=3.2.0,<3.3.0',
-    'pytest-timeout==1.2.0',
-    'pytest-xdist==1.18.2',
-    'pytest-pythonpath==0.7.1',
-    'pytest-sugar==0.8',
+    'pytest-timeout>=1.2.0',
+    'pytest-xdist>=1.18.2',
+    'pytest-pythonpath>=0.7.1',
+    'pytest-sugar>=0.8',
     'pytest-cov',
-    'pytest-flake8==0.9',
+    'pytest-flake8>=0.9',
     'requests',
     'tornado>=4.1',
     'webob',
