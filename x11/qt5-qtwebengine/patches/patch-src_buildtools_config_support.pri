$NetBSD: patch-src_buildtools_config_support.pri,v 1.2 2022/04/18 11:18:19 adam Exp $

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
@@ -38,7 +38,7 @@ defineReplace(qtwebengine_checkWebEngineCoreError) {
 
 # this shuold match webengine-qtpdf-support
 defineReplace(qtwebengine_checkPdfError) {
-    !linux:!win32:!macos:!ios {
+    !linux:!win32:!macos:!ios:!openbsd:!netbsd {
         qtwebengine_skipBuild("QtPdf can be built only on Linux, Windows, macOS or iOS.")
         return(false)
     }
