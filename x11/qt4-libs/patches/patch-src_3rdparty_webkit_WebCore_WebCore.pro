$NetBSD: patch-src_3rdparty_webkit_WebCore_WebCore.pro,v 1.1 2011/09/14 17:58:32 hans Exp $

--- src/3rdparty/webkit/WebCore/WebCore.pro.orig	2010-11-06 02:55:21.000000000 +0100
+++ src/3rdparty/webkit/WebCore/WebCore.pro	2011-01-15 17:31:40.334667952 +0100
@@ -90,7 +90,7 @@ unix {
 }
 
 unix:!mac:*-g++*:QMAKE_CXXFLAGS += -ffunction-sections -fdata-sections 
-unix:!mac:*-g++*:QMAKE_LFLAGS += -Wl,--gc-sections
+unix:!mac:!solaris-*:*-g++*:QMAKE_LFLAGS += -Wl,--gc-sections
 linux*-g++*:QMAKE_LFLAGS += $$QMAKE_LFLAGS_NOUNDEF
 
 CONFIG(release):!CONFIG(standalone_package) {
