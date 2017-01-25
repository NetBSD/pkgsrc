$NetBSD: patch-dom_bindings_GenerateCSS2PropertiesWebIDL.py,v 1.1 2017/01/25 13:24:51 ryoon Exp $

--- dom/bindings/GenerateCSS2PropertiesWebIDL.py.orig	2017-01-16 16:16:52.000000000 +0000
+++ dom/bindings/GenerateCSS2PropertiesWebIDL.py
@@ -16,7 +16,7 @@ def generateLine(propName, extendedAttrs
     return "  [%s] attribute DOMString %s;\n" % (", ".join(extendedAttrs),
                                                  propName)
 def generate(output, idlFilename, preprocessorHeader):
-    cpp = list(buildconfig.substs['CPP'])
+    cpp = shellutil.split(buildconfig.substs['CPP'])
     cpp += shellutil.split(buildconfig.substs['ACDEFINES'])
     cpp.append(preprocessorHeader)
     preprocessed = subprocess.check_output(cpp)
