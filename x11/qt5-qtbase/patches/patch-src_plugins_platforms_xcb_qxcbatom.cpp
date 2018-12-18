$NetBSD: patch-src_plugins_platforms_xcb_qxcbatom.cpp,v 1.1 2018/12/18 09:57:18 adam Exp $

Fix building.

--- src/plugins/platforms/xcb/qxcbatom.cpp.orig	2018-12-13 14:50:05.083875585 +0000
+++ src/plugins/platforms/xcb/qxcbatom.cpp
@@ -40,6 +40,7 @@
 
 #include <QtCore/qglobal.h>
 
+#include <stdlib.h>
 #include <string.h>
 
 #include <algorithm>
