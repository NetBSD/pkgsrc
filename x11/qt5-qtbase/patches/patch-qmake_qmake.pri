$NetBSD: patch-qmake_qmake.pri,v 1.1 2015/10/26 19:03:59 adam Exp $

Fix building on Darwin.

--- qmake/qmake.pri.orig	2015-07-20 09:25:44.000000000 +0000
+++ qmake/qmake.pri
@@ -136,7 +136,7 @@ bootstrap { #Qt code
         SOURCES += qfilesystemengine_unix.cpp qfilesystemiterator_unix.cpp qfsfileengine_unix.cpp
         mac {
           SOURCES += qcore_mac.cpp qsettings_mac.cpp
-          OBJECTIVE_SOURCES += qcore_mac_objc.mm qlocale_mac.mm
+          OBJECTIVE_SOURCES += qcore_mac_objc.mm qlocale_mac.mm qstring_mac.mm
           LIBS += -framework ApplicationServices -framework CoreServices -framework Foundation
         } else {
           SOURCES += qlocale_unix.cpp
