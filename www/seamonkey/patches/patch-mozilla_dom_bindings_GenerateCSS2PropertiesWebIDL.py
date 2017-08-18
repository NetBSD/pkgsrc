$NetBSD: patch-mozilla_dom_bindings_GenerateCSS2PropertiesWebIDL.py,v 1.1 2017/08/18 23:55:07 ryoon Exp $

--- mozilla/dom/bindings/GenerateCSS2PropertiesWebIDL.py.orig	2017-07-07 05:26:25.000000000 +0000
+++ mozilla/dom/bindings/GenerateCSS2PropertiesWebIDL.py
@@ -16,7 +16,7 @@ def generateLine(propName, extendedAttrs
     return "  [%s] attribute DOMString %s;\n" % (", ".join(extendedAttrs),
                                                  propName)
 def generate(output, idlFilename, preprocessorHeader):
-    cpp = list(buildconfig.substs['CPP'])
+    cpp = shellutil.split(buildconfig.substs['CPP'])
     cpp += shellutil.split(buildconfig.substs['ACDEFINES'])
     cpp.append(preprocessorHeader)
     preprocessed = subprocess.check_output(cpp)
