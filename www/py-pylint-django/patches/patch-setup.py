$NetBSD: patch-setup.py,v 1.2 2018/01/31 12:03:47 adam Exp $

Do not install tests.

--- setup.py.orig	2018-01-21 11:57:38.000000000 +0000
+++ setup.py
@@ -6,7 +6,7 @@ import sys
 
 
 _version = '0.9.0'
-_packages = find_packages(exclude=["*.tests", "*.tests.*", "tests.*", "tests"])
+_packages = find_packages(exclude=["test", "test.*"])
 
 _short_description = "pylint-django is a Pylint plugin to aid Pylint in recognising and understanding" \
                      " errors caused when using the Django framework"
