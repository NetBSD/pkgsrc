$NetBSD: patch-setup.py,v 1.13 2022/08/23 09:35:23 adam Exp $

Do not install tests.
https://github.com/sanic-org/sanic/pull/2530/

--- setup.py.orig	2022-08-23 09:13:37.000000000 +0000
+++ setup.py
@@ -61,7 +61,7 @@ setup_kwargs = {
         "Build fast. Run fast."
     ),
     "long_description": long_description,
-    "packages": find_packages(),
+    "packages": find_packages(exclude=["tests", "tests.*"]),
     "package_data": {"sanic": ["py.typed"]},
     "platforms": "any",
     "python_requires": ">=3.7",
