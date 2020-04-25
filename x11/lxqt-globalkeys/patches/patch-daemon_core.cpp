$NetBSD: patch-daemon_core.cpp,v 1.1 2020/04/25 01:34:54 gutteridge Exp $

Fix build with Qt5>=5.14

--- daemon/core.cpp.orig	2019-10-16 15:17:40.000000000 +0000
+++ daemon/core.cpp
@@ -30,6 +30,7 @@
 #include <QScopedArrayPointer>
 #include <QSettings>
 #include <QStandardPaths>
+#include <QFile>
 #include <QTimer>
 #include <QDBusConnectionInterface>
 #include <QDBusServiceWatcher>
