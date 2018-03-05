$NetBSD: patch-setup.py,v 1.4 2018/03/05 09:08:22 adam Exp $

Relax requirements.

--- setup.py.orig	2018-02-03 03:03:31.000000000 +0000
+++ setup.py
@@ -61,19 +61,19 @@ tests_require = [
     'celery>=2.5',
     'coverage<4',
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
     'tox',
