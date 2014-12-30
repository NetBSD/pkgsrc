$NetBSD: patch-Source_ThirdParty_leveldb_Target.pri,v 1.1 2014/12/30 17:23:47 adam Exp $

Build as shared library.

--- Source/ThirdParty/leveldb/Target.pri.orig	2014-11-14 11:29:30.000000000 +0000
+++ Source/ThirdParty/leveldb/Target.pri
@@ -9,7 +9,9 @@ TARGET = leveldb
 
 include(leveldb.pri)
 
-CONFIG += staticlib
+#CONFIG += staticlib
+target.path = $$[QT_INSTALL_LIBS]
+INSTALLS += target
 
 HEADERS += \
     db/builder.h \
