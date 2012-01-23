$NetBSD: patch-src_dbus_qdbusserver.h,v 1.1 2012/01/23 08:16:36 joerg Exp $

http://qt.gitorious.org/qt/qtbase/commit/3de1e6f26b692a8261b40decc2d81286b01c1461

--- src/dbus/qdbusserver.h.orig	2011-12-08 05:06:03.000000000 +0000
+++ src/dbus/qdbusserver.h
@@ -61,7 +61,8 @@ class Q_DBUS_EXPORT QDBusServer: public 
 {
     Q_OBJECT
 public:
-    QDBusServer(const QString &address = "unix:tmpdir=/tmp", QObject *parent = 0);
+    explicit QDBusServer(const QString &address, QObject *parent = 0);
+    explicit QDBusServer(QObject *parent = 0);
     virtual ~QDBusServer();
 
     bool isConnected() const;
