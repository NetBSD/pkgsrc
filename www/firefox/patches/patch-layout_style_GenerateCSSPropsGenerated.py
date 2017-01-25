$NetBSD: patch-layout_style_GenerateCSSPropsGenerated.py,v 1.1 2017/01/25 13:24:51 ryoon Exp $

--- layout/style/GenerateCSSPropsGenerated.py.orig	2017-01-16 16:16:54.000000000 +0000
+++ layout/style/GenerateCSSPropsGenerated.py
@@ -10,7 +10,7 @@ import buildconfig
 from mozbuild import shellutil
 
 def get_properties(preprocessorHeader):
-    cpp = list(buildconfig.substs['CPP'])
+    cpp = shellutil.split(buildconfig.substs['CPP'])
     cpp += shellutil.split(buildconfig.substs['ACDEFINES'])
     cpp.append(preprocessorHeader)
     preprocessed = subprocess.check_output(cpp)
