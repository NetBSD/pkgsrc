$NetBSD: patch-setup.py,v 1.1 2019/12/21 23:51:56 joerg Exp $

Drop Python 2 hack that breaks more than it fixes.

--- setup.py.orig	2019-09-05 09:21:53.000000000 +0000
+++ setup.py
@@ -118,21 +118,4 @@ except ImportError:
             opt['packages'] = setuptools.find_packages(**opt_packages_find)
         return {'metadata': md, 'options': opt}
 
-
-setup_params = {}
-declarative_setup_params = read_configuration('setup.cfg')
-
-# Patch incorrectly decoded package_dir option
-# ``egg_info`` demands native strings failing with unicode under Python 2
-# Ref https://github.com/pypa/setuptools/issues/1136
-if 'package_dir' in declarative_setup_params['options']:
-    declarative_setup_params['options']['package_dir'] = {
-        str(k): str(v)
-        for k, v in declarative_setup_params['options']['package_dir'].items()
-    }
-
-setup_params = dict(setup_params, **declarative_setup_params['metadata'])
-setup_params = dict(setup_params, **declarative_setup_params['options'])
-
-
-__name__ == '__main__' and setuptools.setup(**setup_params)
+__name__ == '__main__' and setuptools.setup()
