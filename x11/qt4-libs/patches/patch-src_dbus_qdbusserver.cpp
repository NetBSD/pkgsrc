$NetBSD: patch-src_dbus_qdbusserver.cpp,v 1.1 2012/01/23 08:16:36 joerg Exp $

http://qt.gitorious.org/qt/qtbase/commit/3de1e6f26b692a8261b40decc2d81286b01c1461

--- src/dbus/qdbusserver.cpp.orig	2011-12-08 05:06:03.000000000 +0000
+++ src/dbus/qdbusserver.cpp
@@ -83,6 +83,31 @@ QDBusServer::QDBusServer(const QString &
 }
 
 /*!
+    Constructs a QDBusServer with the given \a parent. The server will listen
+    for connections in \c {/tmp}.
+*/
+QDBusServer::QDBusServer(QObject *parent)
+    : QObject(parent)
+{
+    const QString address = QLatin1String("unix:tmpdir=/tmp");
+
+    if (!qdbus_loadLibDBus()) {
+        d = 0;
+        return;
+    }
+    d = new QDBusConnectionPrivate(this);
+
+    QMutexLocker locker(&QDBusConnectionManager::instance()->mutex);
+    QDBusConnectionManager::instance()->setConnection(QLatin1String("QDBusServer-") + QString::number(reinterpret_cast<qulonglong>(d)), d);
+
+    QObject::connect(d, SIGNAL(newServerConnection(QDBusConnection)),
+                     this, SIGNAL(newConnection(QDBusConnection)));
+
+    QDBusErrorInternal error;
+    d->setServer(q_dbus_server_listen(address.toUtf8().constData(), error), error);
+}
+
+/*!
     Destructs a QDBusServer
 */
 QDBusServer::~QDBusServer()
