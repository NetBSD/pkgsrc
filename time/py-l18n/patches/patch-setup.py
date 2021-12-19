$NetBSD: patch-setup.py,v 1.1 2021/12/19 14:07:57 wiz Exp $

Fix build with latest setuptools.

--- setup.py.orig	2020-10-31 03:58:31.000000000 +0000
+++ setup.py
@@ -69,7 +69,7 @@ class PredistBuild(object):
         log.info('translation files built successfully')
 
 cmd_classes = {}
-for cmd in ('sdist', 'bdist', 'bdist_egg', 'bdist_rpm', 'bdist_wininst'):
+for cmd in ('sdist', 'bdist', 'bdist_egg', 'bdist_rpm'):
     try:
         cmd_module = getattr(__import__('setuptools.command', fromlist=[cmd]),
                              cmd)
