$NetBSD: patch-configure.pri,v 1.1 2023/04/12 19:24:06 adam Exp $

Always build on Darwin.

--- configure.pri.orig	2023-04-11 08:13:33.000000000 +0000
+++ configure.pri
@@ -446,24 +446,6 @@ defineTest(qtwebengine_isWindowsPlatform
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
     return(true)
 }
 
