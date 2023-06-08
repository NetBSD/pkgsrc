$NetBSD: patch-src_buildtools_config_support.pri,v 1.3 2023/06/08 20:38:06 markd Exp $

support netbsd openbsd
build with python3

--- src/buildtools/config/support.pri.orig
+++ src/buildtools/config/support.pri
@@ -5,7 +5,7 @@ defineTest(qtwebengine_skipBuild) {
 
 # this should match webengine-core-support
 defineReplace(qtwebengine_checkWebEngineCoreError) {
-    !linux:!win32:!macos {
+    !linux:!win32:!macos:!openbsd:!netbsd {
         qtwebengine_skipBuild("QtWebEngine can be built only on Linux, Windows or macOS.")
         return(false)
     }
@@ -21,7 +21,7 @@ defineReplace(qtwebengine_checkWebEngine
     !qtwebengine_checkForGperf(QtWebEngine):return(false)
     !qtwebengine_checkForBison(QtWebEngine):return(false)
     !qtwebengine_checkForFlex(QtWebEngine):return(false)
-    !qtwebengine_checkForPython2(QtWebEngine):return(false)
+    !qtwebengine_checkForPython(QtWebEngine):return(false)
     !qtwebengine_checkForNodejs(QtWebEngine):return(false)
     !qtwebengine_checkForSanitizer(QtWebEngine):return(false)
     linux:!qtwebengine_checkForPkgCfg(QtWebEngine):return(false)
@@ -39,7 +39,7 @@ defineReplace(qtwebengine_checkWebEngine
 
 # this shuold match webengine-qtpdf-support
 defineReplace(qtwebengine_checkPdfError) {
-    !linux:!win32:!macos:!ios {
+    !linux:!win32:!macos:!ios:!openbsd:!netbsd {
         qtwebengine_skipBuild("QtPdf can be built only on Linux, Windows, macOS or iOS.")
         return(false)
     }
@@ -51,7 +51,7 @@ defineReplace(qtwebengine_checkPdfError)
     !qtwebengine_checkForGperf(QtPdf):return(false)
     !qtwebengine_checkForBison(QtPdf):return(false)
     !qtwebengine_checkForFlex(QtPdf):return(false)
-    !qtwebengine_checkForPython2(QtPdf):return(false)
+    !qtwebengine_checkForPython(QtPdf):return(false)
     !qtwebengine_checkForSanitizer(QtPdf):return(false)
     linux:!qtwebengine_checkForPkgCfg(QtPdf):return(false)
     linux:!qtwebengine_checkForHostPkgCfg(QtPdf):return(false)
@@ -147,10 +147,10 @@ defineTest(qtwebengine_checkForFlex) {
     return(true)
 }
 
-defineTest(qtwebengine_checkForPython2) {
+defineTest(qtwebengine_checkForPython) {
     module = $$1
-    !qtConfig(webengine-python2) {
-        qtwebengine_skipBuild("Python version 2 (2.7.5 or later) is required to build $${module}.")
+    !qtConfig(webengine-python) {
+        qtwebengine_skipBuild("Python is required to build $${module}.")
         return(false)
     }
     return(true)
