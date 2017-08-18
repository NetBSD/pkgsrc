$NetBSD: patch-mozilla_layout_style_GenerateCSSPropsGenerated.py,v 1.1 2017/08/18 23:55:07 ryoon Exp $

--- mozilla/layout/style/GenerateCSSPropsGenerated.py.orig	2017-07-07 05:28:56.000000000 +0000
+++ mozilla/layout/style/GenerateCSSPropsGenerated.py
@@ -10,7 +10,7 @@ import buildconfig
 from mozbuild import shellutil
 
 def get_properties(preprocessorHeader):
-    cpp = list(buildconfig.substs['CPP'])
+    cpp = shellutil.split(buildconfig.substs['CPP'])
     cpp += shellutil.split(buildconfig.substs['ACDEFINES'])
     cpp.append(preprocessorHeader)
     preprocessed = subprocess.check_output(cpp)
