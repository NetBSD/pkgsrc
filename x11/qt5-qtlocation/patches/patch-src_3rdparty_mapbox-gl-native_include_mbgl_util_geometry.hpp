$NetBSD: patch-src_3rdparty_mapbox-gl-native_include_mbgl_util_geometry.hpp,v 1.1 2024/06/16 11:33:39 markd Exp $

https://bugreports.qt.io/browse/QTBUG-122589
fix build with gcc14

--- src/3rdparty/mapbox-gl-native/include/mbgl/util/geometry.hpp.orig	2024-05-08 05:14:45.000000000 +0000
+++ src/3rdparty/mapbox-gl-native/include/mbgl/util/geometry.hpp
@@ -3,6 +3,7 @@
 #include <mapbox/geometry/geometry.hpp>
 #include <mapbox/geometry/point_arithmetic.hpp>
 #include <mapbox/geometry/for_each_point.hpp>
+#include <cstdint>
 
 namespace mbgl {
 
