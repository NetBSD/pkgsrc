$NetBSD: patch-setup.py,v 1.11 2022/01/27 09:57:08 wiz Exp $

Remove upper bound, pkgsrc version is 6.x

--- setup.py.orig	2022-01-06 10:26:24.000000000 +0000
+++ setup.py
@@ -90,28 +90,28 @@ requirements = [
     ujson,
     "aiofiles>=0.6.0",
     "websockets>=10.0",
-    "multidict>=5.0,<6.0",
+    "multidict>=5.0",
 ]
 
 tests_require = [
     "sanic-testing>=0.7.0",
-    "pytest==6.2.5",
-    "coverage==5.3",
-    "gunicorn==20.0.4",
+    "pytest",
+    "coverage",
+    "gunicorn",
     "pytest-cov",
     "beautifulsoup4",
     "pytest-sanic",
     "pytest-sugar",
     "pytest-benchmark",
-    "chardet==3.*",
+    "chardet",
     "flake8",
     "black",
     "isort>=5.0.0",
     "bandit",
-    "mypy>=0.901,<0.910",
+    "mypy>=0.901",
     "docutils",
     "pygments",
-    "uvicorn<0.15.0",
+    "uvicorn",
     types_ujson,
 ]
 
