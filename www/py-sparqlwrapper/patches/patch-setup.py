$NetBSD: patch-setup.py,v 1.2 2021/12/06 14:14:35 wiz Exp $

Fix for Python 3.6 and latest setuptools.

--- setup.py.orig	2019-04-18 10:02:26.000000000 +0000
+++ setup.py
@@ -23,7 +23,7 @@ _version_re = re.compile(r'__version__\s
 _authors_re = re.compile(r'__authors__\s*=\s*"(.*)"')
 _url_re = re.compile(r'__url__\s*=\s*"(.*)"')
 
-for line in open('SPARQLWrapper/__init__.py'):
+for line in open('SPARQLWrapper/__init__.py', encoding='utf-8'):
 
     version_match = _version_re.match(line)
     if version_match:
@@ -75,8 +75,6 @@ setup(
         'Topic :: Software Development :: Libraries :: Python Modules',
       ],
       keywords = ['python', 'sparql', 'rdf', 'rdflib'],
-      use_2to3 = True,
-      use_2to3_fixers = ['custom_fixers'],
       project_urls={
         'Home': 'https://rdflib.github.io/sparqlwrapper/',
         'Documentation': 'https://rdflib.github.io/sparqlwrapper/doc/',
