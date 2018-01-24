$NetBSD: patch-setup.py,v 1.3 2018/01/24 10:20:32 adam Exp $

Relax requirements.

--- setup.py.orig	2018-01-17 21:06:54.000000000 +0000
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
-    'pytest>=3.2.0,<3.3.0',
-    'pytest-timeout==1.2.0',
-    'pytest-xdist==1.18.2',
-    'pytest-pythonpath==0.7.1',
-    'pytest-sugar==0.9.0',
+    'pytest>=3.2.0',
+    'pytest-timeout>=1.2.0',
+    'pytest-xdist>=1.18.2',
+    'pytest-pythonpath>=0.7.1',
+    'pytest-sugar>=0.9.0',
     'pytest-cov',
-    'pytest-flake8==0.9.1',
+    'pytest-flake8>=0.9.1',
     'requests',
     'tornado>=4.1',
     'webob',
