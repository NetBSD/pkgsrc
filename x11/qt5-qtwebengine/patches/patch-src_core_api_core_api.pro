$NetBSD: patch-src_core_api_core_api.pro,v 1.1 2021/08/03 21:04:36 markd Exp $

Index: src/core/api/core_api.pro
--- src/core/api/core_api.pro.orig
+++ src/core/api/core_api.pro
@@ -67,7 +67,7 @@ SOURCES = \
     qwebengineurlschemehandler.cpp
 
 ### Qt6 Remove this workaround
-unix:!isEmpty(QMAKE_LFLAGS_VERSION_SCRIPT):!static {
+linux:!isEmpty(QMAKE_LFLAGS_VERSION_SCRIPT):!static {
     SOURCES += qtbug-60565.cpp \
                qtbug-61521.cpp
 }
