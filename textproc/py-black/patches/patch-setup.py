$NetBSD: patch-setup.py,v 1.1 2022/01/13 19:40:07 wiz Exp $

--- setup.py.orig	2021-12-05 22:41:57.000000000 +0000
+++ setup.py
@@ -99,7 +99,7 @@ setup(
     install_requires=[
         "click>=7.1.2",
         "platformdirs>=2",
-        "tomli>=0.2.6,<2.0.0",
+        "tomli>=0.2.6",
         "typed-ast>=1.4.2; python_version < '3.8' and implementation_name == 'cpython'",
         "pathspec>=0.9.0, <1",
         "dataclasses>=0.6; python_version < '3.7'",
