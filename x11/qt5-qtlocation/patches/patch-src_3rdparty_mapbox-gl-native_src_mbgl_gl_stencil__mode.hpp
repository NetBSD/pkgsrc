$NetBSD: patch-src_3rdparty_mapbox-gl-native_src_mbgl_gl_stencil__mode.hpp,v 1.1 2024/06/16 11:33:39 markd Exp $


https://bugreports.qt.io/browse/QTBUG-122589
fix build with gcc14

--- src/3rdparty/mapbox-gl-native/src/mbgl/gl/stencil_mode.hpp.orig	2024-05-08 05:14:45.000000000 +0000
+++ src/3rdparty/mapbox-gl-native/src/mbgl/gl/stencil_mode.hpp
@@ -1,6 +1,7 @@
 #pragma once
 
 #include <mbgl/util/variant.hpp>
+#include <cstdint>
 
 namespace mbgl {
 namespace gl {
