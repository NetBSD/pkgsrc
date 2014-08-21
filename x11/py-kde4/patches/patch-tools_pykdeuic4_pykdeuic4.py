$NetBSD: patch-tools_pykdeuic4_pykdeuic4.py,v 1.1 2014/08/21 21:34:33 wiz Exp $

--- tools/pykdeuic4/pykdeuic4.py.orig	2014-01-02 19:29:05.000000000 +0000
+++ tools/pykdeuic4/pykdeuic4.py
@@ -23,6 +23,7 @@ import sys
 import time
 import optparse
 
+from PyQt4 import QtCore
 from PyQt4.uic.Compiler import indenter, compiler
 from PyQt4.uic.Compiler import qtproxies
 from PyQt4.uic.objcreator import MATCH,NO_MATCH
@@ -101,7 +102,12 @@ def processUI(uifile, output_filename=No
     output.write(HEADER % (uifile, time.ctime()))
     indenter.indentwidth = indent
     comp = compiler.UICompiler()
-    winfo = comp.compileUi(uifile, output, None)
+    pyqt_version_tuple = tuple(map(int, QtCore.PYQT_VERSION_STR.split(".")))
+    # the method signature for compileUI changed in 4.10.0
+    if pyqt_version_tuple < (4,10,0):
+        winfo = comp.compileUi(uifile, output, None)
+    else:
+        winfo = comp.compileUi(uifile, output, None, "")
 
     if exe:
         output.write(DISPLAY_CODE % winfo["uiclass"])
