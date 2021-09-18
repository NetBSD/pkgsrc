$NetBSD: patch-python_mozbuild_mozbuild_configure_constants.py,v 1.1 2021/09/18 22:10:22 jklos Exp $

--- python/mozbuild/mozbuild/configure/constants.py.orig	2017-04-11 02:13:23.000000000 +0000
+++ python/mozbuild/mozbuild/configure/constants.py
@@ -40,7 +40,7 @@ Kernel = EnumString.subclass(
 
 CPU_bitness = {
     'aarch64': 64,
-    'Alpha': 32,
+    'Alpha': 64,
     'arm': 32,
     'hppa': 32,
     'ia64': 64,
