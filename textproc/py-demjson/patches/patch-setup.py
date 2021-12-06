$NetBSD: patch-setup.py,v 1.2 2021/12/06 15:03:50 wiz Exp $

Always use setuptools.

--- setup.py.orig	2015-12-22 20:02:25.000000000 +0000
+++ setup.py
@@ -9,23 +9,8 @@ try:
 except AttributeError:
     py_major = sys.version_info[0]
 
-distmech = None
-if py_major >= 3:
-    # Python 3, use setuptools first
-    try:
-        from setuptools import setup
-        distmech = 'setuptools'
-    except ImportError:
-        from distutils.core import setup
-        distmech = 'distutils'
-else:
-    # Python 2, use distutils first
-    try:
-        from distutils.core import setup
-        distmech = 'distutils'
-    except ImportError:
-        from setuptools import setup
-        distmech = 'setuptools'
+from setuptools import setup
+distmech = 'setuptools'
 
 if False:
     sys.stdout.write("Using Python:    %s\n" % sys.version.split(None,1)[0])
@@ -33,20 +18,6 @@ if False:
 
 py3extra = {}
 
-if py_major >= 3:
-    # Make sure 2to3 gets run
-    if distmech == 'setuptools':
-        py3extra['use_2to3'] = True
-        #py3extra['convert_2to3_doctests'] = ['src/your/module/README.txt']
-        #py3extra['use_2to3_fixers'] = ['your.fixers']
-    elif distmech == 'distutils':
-        import distutils, distutils.command, distutils.command.build_py, distutils.command.build_scripts
-        cmdclass = {
-            'build_py':      distutils.command.build_py.build_py_2to3,
-            'build_scripts': distutils.command.build_scripts.build_scripts_2to3
-            }
-        py3extra['cmdclass'] = cmdclass
-
 setup( name=name,
        version=version,
        py_modules=[name],
