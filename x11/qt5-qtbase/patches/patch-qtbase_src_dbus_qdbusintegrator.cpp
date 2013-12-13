$NetBSD: patch-qtbase_src_dbus_qdbusintegrator.cpp,v 1.1 2013/12/13 14:38:35 ryoon Exp $

--- qtbase/src/dbus/qdbusintegrator.cpp.orig	2013-11-27 01:01:11.000000000 +0000
+++ qtbase/src/dbus/qdbusintegrator.cpp
@@ -76,7 +76,7 @@ QT_BEGIN_NAMESPACE
 static bool isDebugging;
 #define qDBusDebug              if (!::isDebugging); else qDebug
 
-Q_GLOBAL_STATIC_WITH_ARGS(const QString, orgFreedesktopDBusString, (QLatin1String(DBUS_SERVICE_DBUS)))
+Q_GLOBAL_STATIC_WITH_ARGS(QString, orgFreedesktopDBusString, (QLatin1String(DBUS_SERVICE_DBUS)))
 
 static inline QString dbusServiceString()
 { return *orgFreedesktopDBusString(); }
