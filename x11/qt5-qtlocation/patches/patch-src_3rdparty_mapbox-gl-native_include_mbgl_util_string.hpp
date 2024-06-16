$NetBSD: patch-src_3rdparty_mapbox-gl-native_include_mbgl_util_string.hpp,v 1.1 2024/06/16 11:33:39 markd Exp $

https://bugreports.qt.io/browse/QTBUG-122589
fix build with gcc14

--- src/3rdparty/mapbox-gl-native/include/mbgl/util/string.hpp.orig	2024-05-08 05:14:45.000000000 +0000
+++ src/3rdparty/mapbox-gl-native/include/mbgl/util/string.hpp
@@ -4,6 +4,7 @@
 #include <string>
 #include <cassert>
 #include <cstdlib>
+#include <cstdint>
 #include <exception>
 
 // Polyfill needed by Qt when building for Android with GCC
