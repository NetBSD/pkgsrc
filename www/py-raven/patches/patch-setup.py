$NetBSD: patch-setup.py,v 1.6 2024/10/14 07:24:52 wiz Exp $

Relax requirements.

Remove unused anyjson test dependency.

--- setup.py.orig	2018-12-15 19:00:21.000000000 +0000
+++ setup.py
@@ -70,26 +70,25 @@ if sys.version_info >= (3, 5):
 tests_require = [
     'bottle',
     'celery>=2.5',
-    'coverage<4',
+    'coverage',
     'exam>=0.5.2',
-    'flake8==3.5.0',
+    'flake8>=3.5.0',
     'logbook',
     'mock',
     'nose',
     'pytz',
-    'pytest>=3.2.0,<3.3.0',
-    'pytest-timeout==1.2.1',
-    'pytest-xdist==1.18.2',
-    'pytest-pythonpath==0.7.2',
-    'pytest-cov==2.5.1',
-    'pytest-flake8==1.0.0',
+    'pytest>=3.2.0',
+    'pytest-timeout>=1.2.1',
+    'pytest-xdist>=1.18.2',
+    'pytest-pythonpath>=0.7.1',
+    'pytest-cov>=2.5.1',
+    'pytest-flake8>=1.0.0',
     'requests',
-    'tornado>=4.1,<5.0',
+    'tornado>=4.1',
     'tox',
     'webob',
     'webtest',
     'wheel',
-    'anyjson',
     'ZConfig',
 ] + (
     flask_requires + flask_tests_requires
