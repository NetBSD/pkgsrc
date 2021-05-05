$NetBSD: patch-setup.py,v 1.1 2021/05/05 09:54:42 adam Exp $

Fix for Python 3.6.

--- setup.py.orig	2021-05-05 09:39:48.000000000 +0000
+++ setup.py
@@ -23,7 +23,7 @@ _version_re = re.compile(r'__version__\s
 _authors_re = re.compile(r'__authors__\s*=\s*"(.*)"')
 _url_re = re.compile(r'__url__\s*=\s*"(.*)"')
 
-for line in open('SPARQLWrapper/__init__.py'):
+for line in open('SPARQLWrapper/__init__.py', encoding='utf-8'):
 
     version_match = _version_re.match(line)
     if version_match:
