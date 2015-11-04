$NetBSD: patch-setup.py,v 1.1 2015/11/04 09:45:05 wiz Exp $

Avoid conflicts with other python versions of this package.

--- setup.py.orig	2015-08-28 03:42:04.000000000 +0000
+++ setup.py
@@ -244,7 +244,7 @@ setup(
     maintainer_email='waylan.limberg [at] icloud.com',
     license='BSD License',
     packages=['markdown', 'markdown.extensions'],
-    scripts=['bin/%s' % SCRIPT_NAME],
+    scripts=['bin/%s' % SCRIPT_NAME+sys.version[0:3]],
     cmdclass={
         'install_scripts': md_install_scripts,
         'build_docs': build_docs,
