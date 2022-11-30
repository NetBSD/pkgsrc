$NetBSD: patch-setup.py,v 1.1 2022/11/30 09:33:05 adam Exp $

Do not require pytest-flake8 and pytest-isort as PkgSrc does have Python 2.7
versions anymore.

--- setup.py.orig	2022-11-30 09:26:24.000000000 +0000
+++ setup.py
@@ -49,7 +49,7 @@ setup(
     setup_requires=pytest_runner,
     test_suite='tinycss2.test',
     tests_require=[
-        'pytest-runner', 'pytest-cov', 'pytest-flake8', 'pytest-isort'],
+        'pytest-runner', 'pytest-cov'],
     extras_require={'test': [
-        'pytest-runner', 'pytest-cov', 'pytest-flake8', 'pytest-isort']},
+        'pytest-runner', 'pytest-cov']},
 )
