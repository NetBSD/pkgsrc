$NetBSD: patch-setup.py,v 1.1 2017/11/26 17:40:05 adam Exp $

Relax requirements.

--- setup.py.orig	2017-11-26 17:23:27.000000000 +0000
+++ setup.py
@@ -60,20 +60,20 @@ tests_require = [
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
     'pytest-assume',
     'pytest-cov',
-    'pytest-flake8==0.9',
+    'pytest-flake8>=0.9',
     'requests',
     'tornado>=4.1',
     'webob',
