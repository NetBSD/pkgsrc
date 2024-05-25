$NetBSD: patch-configure.pri,v 1.3 2024/05/25 14:21:23 adam Exp $

Always build on Darwin.
Build with python 3

--- configure.pri.orig	2023-05-05 08:39:51.000000000 +0000
+++ configure.pri
@@ -7,20 +7,7 @@ QTWEBENGINE_SOURCE_TREE = $$PWD
 equals(QMAKE_HOST.os, Windows): EXE_SUFFIX = .exe
 
 defineTest(isPythonVersionSupported) {
-    python = $$system_quote($$system_path($$1))
-    python_version = $$system('$$python -c "import sys; print(sys.version_info[0:3])"')
-    python_version ~= s/[()]//g
-    python_version = $$split(python_version, ',')
-    python_major_version = $$first(python_version)
-    greaterThan(python_major_version, 2) {
-        qtLog("Python version 3 is not supported by Chromium.")
-        return(false)
-    }
-    python_minor_version = $$member(python_version, 1)
-    python_patch_version = $$member(python_version, 2)
-    greaterThan(python_major_version, 1): greaterThan(python_minor_version, 6): greaterThan(python_patch_version, 4): return(true)
-    qtLog("Unsupported python version: $${python_major_version}.$${python_minor_version}.$${python_patch_version}.")
-    return(false)
+    return(true)
 }
 
 defineTest(qtConfTest_detectJumboBuild) {
@@ -52,10 +39,10 @@ defineTest(qtConfReport_jumboBuild) {
     qtConfReportPadded($${1}, $$mergeLimit)
 }
 
-defineTest(qtConfTest_detectPython2) {
-    python = $$qtConfFindInPath("python2$$EXE_SUFFIX")
+defineTest(qtConfTest_detectPython) {
+    python = $$qtConfFindInPath("python$$EXE_SUFFIX")
     isEmpty(python) {
-        qtLog("'python2$$EXE_SUFFIX' not found in PATH. Checking for 'python$$EXE_SUFFIX'.")
+        qtLog("'python$$EXE_SUFFIX' not found in PATH. Checking for 'python$$EXE_SUFFIX'.")
         python = $$qtConfFindInPath("python$$EXE_SUFFIX")
     }
     isEmpty(python) {
@@ -63,11 +50,11 @@ defineTest(qtConfTest_detectPython2) {
         return(false)
     }
     !isPythonVersionSupported($$python) {
-        qtLog("A suitable Python 2 executable could not be located.")
+        qtLog("A suitable Python executable could not be located.")
         return(false)
     }
 
-    # Make tests.python2.location available in configure.json.
+    # Make tests.python.location available in configure.json.
     $${1}.location = $$clean_path($$python)
     export($${1}.location)
     $${1}.cache += location
@@ -442,28 +429,6 @@ defineTest(qtwebengine_isWindowsPlatform
 }
 
 defineTest(qtwebengine_isMacOsPlatformSupported) {
-    !qtwebengine_isMinXcodeVersion(10, 0, 0) {
-        qtwebengine_platformError("requires at least version 10.0.0, but using Xcode version $${QMAKE_XCODE_VERSION}.")
-        return(false)
-    }
-    !clang|intel_icc {
-        qtwebengine_platformError("requires Clang.")
-        return(false)
-    }
-    # We require macOS 10.13 (darwin version 17.0.0) or newer.
-    darwin_major_version = $$section(QMAKE_HOST.version, ., 0, 0)
-    lessThan(darwin_major_version, 17) {
-        qtwebengine_platformError("requires macOS version 10.13 or newer.")
-        return(false)
-    }
-    !qtwebengine_isMinOSXSDKVersion(10, 13): {
-        qtwebengine_platformError("requires a macOS SDK version of 10.13 or newer. Current version is $${WEBENGINE_OSX_SDK_PRODUCT_VERSION}.")
-        return(false)
-    }
-    CONFIG(debug, debug|release):isUniversal(){
-        qtwebengine_platformError("Universal builds can not be done with debug configuration due to large binary size.")
-        return(false)
-    }
     return(true)
 }
 
