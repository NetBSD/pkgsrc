$NetBSD: patch-setup.py,v 1.3 2021/12/30 13:36:26 adam Exp $

Fix for latest setuptools.

--- setup.py.orig	2019-04-18 10:02:26.000000000 +0000
+++ setup.py
@@ -75,8 +75,6 @@ setup(
         'Topic :: Software Development :: Libraries :: Python Modules',
       ],
       keywords = ['python', 'sparql', 'rdf', 'rdflib'],
-      use_2to3 = True,
-      use_2to3_fixers = ['custom_fixers'],
       project_urls={
         'Home': 'https://rdflib.github.io/sparqlwrapper/',
         'Documentation': 'https://rdflib.github.io/sparqlwrapper/doc/',
