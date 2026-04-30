$NetBSD: patch-configure.cmake,v 1.2 2026/04/30 06:39:34 adam Exp $

* Based on OpenBSD's qt6-qtwebengine patches, and
  pkgsrc's qt5-qtwebengine patches

--- configure.cmake.orig	2025-11-14 07:55:10.000000000 +0000
+++ configure.cmake
@@ -116,7 +116,7 @@ if(Python3_EXECUTABLE)
     )
 endif()
 
-if(LINUX)
+if(UNIX)
    qt_webengine_configure_check_for_ulimit()
 endif()
 
@@ -302,16 +302,16 @@ unset(targets_to_check)
 
 qt_webengine_configure_check("supported-platform"
     MODULES QtWebEngine
-    CONDITION LINUX OR WIN32 OR MACOS
+    CONDITION UNIX OR WIN32 OR MACOS
     MESSAGE "Build can be done only on Linux, Windows or macOS."
 )
 qt_webengine_configure_check("supported-platform"
     MODULES QtPdf
-    CONDITION LINUX OR WIN32 OR MACOS OR IOS OR ANDROID
+    CONDITION UNIX OR WIN32 OR MACOS OR IOS OR ANDROID
     MESSAGE "Build can be done only on Linux, Windows, macO, iOS and Android."
 )
 
-if(LINUX AND CMAKE_CROSSCOMPILING)
+if(UNIX AND CMAKE_CROSSCOMPILING)
     set(supported_targets "arm" "arm64" "armv7-a" "x86_64")
     qt_webengine_configure_check("supported-arch"
         MODULES QtWebEngine QtPdf
@@ -381,42 +381,42 @@ qt_webengine_configure_check("flex"
 )
 qt_webengine_configure_check("pkg-config"
     MODULES QtWebEngine QtPdf
-    CONDITION NOT LINUX OR PkgConfig_FOUND
+    CONDITION NOT UNIX OR PkgConfig_FOUND
     MESSAGE "A pkg-config support is required."
     DOCUMENTATION "A pkg-config binary."
     TAGS LINUX_PLATFORM
 )
-qt_webengine_configure_check("glibc"
-    MODULES QtWebEngine
-    CONDITION NOT LINUX OR TEST_glibc
-    MESSAGE "A suitable version >= ${QT_CONFIGURE_CHECK_glibc_version} of glibc is required."
-    DOCUMENTATION "Glibc library at least ${QT_CONFIGURE_CHECK_glibc_version} version or later."
-    TAGS LINUX_PLATFORM
-)
+#qt_webengine_configure_check("glibc"
+#    MODULES QtWebEngine
+#    CONDITION NOT UNIX OR TEST_glibc
+#    MESSAGE "A suitable version >= ${QT_CONFIGURE_CHECK_glibc_version} of glibc is required."
+#    DOCUMENTATION "Glibc library at least ${QT_CONFIGURE_CHECK_glibc_version} version or later."
+#    TAGS LINUX_PLATFORM
+#)
 qt_webengine_configure_check("mesa-headers"
     MODULES QtWebEngine
-    CONDITION NOT LINUX OR TEST_khr
+    CONDITION NOT UNIX OR APPLE OR TEST_khr
     MESSAGE "Build requires Khronos development headers for build - see mesa/libegl1-mesa-dev"
     DOCUMENTATION "Mesa development headers."
     TAGS LINUX_PLATFORM
 )
 qt_webengine_configure_check("fontconfig"
     MODULES QtWebEngine
-    CONDITION NOT LINUX OR FONTCONFIG_FOUND
+    CONDITION NOT UNIX OR FONTCONFIG_FOUND
     MESSAGE "Build requires fontconfig."
     DOCUMENTATION "Fontconfig"
     TAGS LINUX_PKG_CONFIG
 )
 qt_webengine_configure_check("nss"
     MODULES QtWebEngine
-    CONDITION NOT LINUX OR NSS_FOUND
+    CONDITION NOT UNIX OR NSS_FOUND
     MESSAGE "Build requires nss >= ${QT_CONFIGURE_CHECK_nss_version}."
     DOCUMENTATION "Nss library is at least ${QT_CONFIGURE_CHECK_nss_version} version."
     TAGS LINUX_PLATFORM
 )
 qt_webengine_configure_check("dbus"
     MODULES QtWebEngine
-    CONDITION NOT LINUX OR DBUS_FOUND
+    CONDITION NOT UNIX OR DBUS_FOUND
     MESSAGE "Build requires dbus."
     DOCUMENTATION "Dbus"
     TAGS LINUX_PKG_CONFIG
@@ -424,8 +424,8 @@ qt_webengine_configure_check("dbus"
 qt_webengine_configure_check("compiler"
     MODULES QtWebEngine
     CONDITION MSVC OR
-        (LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
-        (LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR
+        (UNIX AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
+        (UNIX AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR
         (MACOS AND CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
     MESSAGE
         "${CMAKE_CXX_COMPILER_ID} compiler is not supported."
@@ -433,8 +433,8 @@ qt_webengine_configure_check("compiler"
 qt_webengine_configure_check("compiler"
     MODULES QtPdf
     CONDITION MSVC OR
-        (LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
-        (LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR
+        (UNIX AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
+        (UNIX AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR
         (APPLE AND CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang") OR
         (ANDROID AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR
         (MINGW AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
@@ -466,7 +466,7 @@ qt_webengine_configure_check("msvc-2022"
 
 qt_webengine_configure_check("gcc"
     MODULES QtWebEngine
-    CONDITION NOT (LINUX OR MINGW) OR NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR
+    CONDITION NOT (UNIX OR MINGW) OR NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR
               NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS ${QT_CONFIGURE_CHECK_gcc_version}
     MESSAGE "Gcc version must be at least ${QT_CONFIGURE_CHECK_gcc_version}"
     DOCUMENTATION "Gcc version must be at least ${QT_CONFIGURE_CHECK_gcc_version} to compile QtWebEngine."
@@ -475,7 +475,7 @@ qt_webengine_configure_check("gcc"
 
 qt_webengine_configure_check("clang"
     MODULES QtWebEngine
-    CONDITION NOT (LINUX OR MINGW) OR NOT CMAKE_CXX_COMPILER_ID STREQUAL "CLANG" OR
+    CONDITION NOT (UNIX OR MINGW) OR NOT CMAKE_CXX_COMPILER_ID STREQUAL "CLANG" OR
               NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS ${QT_CONFIGURE_CHECK_calng_version}
     MESSAGE "Clang version must be at least ${QT_CONFIGURE_CHECK_clang_version}"
     DOCUMENTATION "Clang version must be at least ${QT_CONFIGURE_CHECK_clang_version} to compile QtWebEngine."
@@ -484,7 +484,7 @@ qt_webengine_configure_check("clang"
 
 qt_webengine_configure_check("gcc_for_pdf"
     MODULES QtPdf
-    CONDITION NOT (LINUX OR MINGW) OR NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR
+    CONDITION NOT (UNIX OR MINGW) OR NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR
               NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS ${QT_CONFIGURE_CHECK_gcc_for_pdf_version}
     MESSAGE "GCC version must be at least ${QT_CONFIGURE_CHECK_gcc_for_pdf_version}"
     DOCUMENTATION "Gcc version must be at least ${QT_CONFIGURE_CHECK_gcc_for_pdf_version}"
@@ -516,7 +516,7 @@ foreach(x_lib ${x_libs})
     string(TOLOWER ${x_lib} lib)
     qt_webengine_configure_check("${lib}"
         MODULES QtWebEngine
-        CONDITION NOT TARGET Qt6::Gui OR NOT LINUX OR NOT QT_FEATURE_xcb OR ${x_lib}_FOUND
+        CONDITION NOT TARGET Qt6::Gui OR NOT UNIX OR NOT QT_FEATURE_xcb OR ${x_lib}_FOUND
         MESSAGE "Could not find ${lib} library for qpa-xcb support."
         DOCUMENTATION "${lib}"
         TAGS LINUX_XCB
@@ -743,7 +743,7 @@ qt_feature("webengine-system-openh264" P
 
 qt_feature("webengine-ozone-x11" PRIVATE
     LABEL "Support X11 on qpa-xcb"
-    CONDITION LINUX
+    CONDITION UNIX
         AND TARGET Qt::Gui
         AND QT_FEATURE_xcb
         AND qpa_xcb_support_check
