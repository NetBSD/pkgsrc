$NetBSD: patch-src_plugins_platforms_xcb_qxcbconnection__basic.h,v 1.2 2020/01/21 20:25:37 adam Exp $

Include <cstdlib> for std::free().

--- src/plugins/platforms/xcb/qxcbconnection_basic.h.orig	2020-01-21 16:01:11.717518124 +0000
+++ src/plugins/platforms/xcb/qxcbconnection_basic.h
@@ -50,6 +50,7 @@
 
 #include <xcb/xcb.h>
 
+#include <cstdlib>
 #include <memory>
 
 QT_BEGIN_NAMESPACE
