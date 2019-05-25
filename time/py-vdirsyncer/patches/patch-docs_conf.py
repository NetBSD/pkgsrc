$NetBSD: patch-docs_conf.py,v 1.1 2019/05/25 06:58:10 wiz Exp $

Follow advice from setuptools_scm how to use it.
https://github.com/pimutils/vdirsyncer/pull/799

--- docs/conf.py.orig	2018-06-13 16:54:02.000000000 +0000
+++ docs/conf.py
@@ -3,7 +3,7 @@
 import datetime
 import os
 
-import setuptools_scm
+from pkg_resources import get_distribution
 
 extensions = ['sphinx.ext.autodoc']
 
@@ -16,7 +16,7 @@ project = u'vdirsyncer'
 copyright = (u'2014-{}, Markus Unterwaditzer & contributors'
              .format(datetime.date.today().strftime('%Y')))
 
-release = setuptools_scm.get_version(root='..', relative_to=__file__)
+release = get_distribution('vdirsyncer').version
 version = '.'.join(release.split('.')[:2])  # The short X.Y version.
 
 rst_epilog = '.. |vdirsyncer_version| replace:: %s' % release
