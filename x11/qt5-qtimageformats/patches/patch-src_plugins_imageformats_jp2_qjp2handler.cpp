$NetBSD: patch-src_plugins_imageformats_jp2_qjp2handler.cpp,v 1.1 2020/08/07 02:01:38 gutteridge Exp $

Needs math.h for pow().

--- src/plugins/imageformats/jp2/qjp2handler.cpp.orig	2020-04-27 07:24:21.000000000 +0000
+++ src/plugins/imageformats/jp2/qjp2handler.cpp
@@ -44,6 +44,7 @@
 #include "qvariant.h"
 #include "qcolor.h"
 
+#include <math.h>
 #include <jasper/jasper.h>
 
 QT_BEGIN_NAMESPACE
