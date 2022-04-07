$NetBSD: patch-setup.py,v 1.1 2022/04/07 10:19:57 adam Exp $

Do not install configuration files.

--- setup.py.orig	2022-04-07 10:14:10.000000000 +0000
+++ setup.py
@@ -205,7 +205,6 @@ setup_args = dict(
                 'widgetsnbextension/static/extension.js',
                 'widgetsnbextension/static/extension.js.map'
         ]),
-        ('etc/jupyter/nbconfig/notebook.d' , ['widgetsnbextension.json'])
     ],
     zip_safe=False,
     include_package_data = True,
