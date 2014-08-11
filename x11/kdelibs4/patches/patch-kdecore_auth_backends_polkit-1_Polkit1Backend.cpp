$NetBSD: patch-kdecore_auth_backends_polkit-1_Polkit1Backend.cpp,v 1.1 2014/08/11 21:18:03 markd Exp $

From: Martin T. H. Sandsmark <martin.sandsmark@kde.org>
Date: Mon, 21 Jul 2014 20:52:40 +0000
Subject: Use dbus system bus name instead of PID for authentication.
X-Git-Url: http://quickgit.kde.org/?p=kdelibs.git&a=commitdiff&h=e4e7b53b71e2659adaf52691d4accc3594203b23
---
Use dbus system bus name instead of PID for authentication.

Using the PID for authentication is prone to a PID reuse
race condition, and a security issue.

REVIEW: 119323
---


--- kdecore/auth/backends/polkit-1/Polkit1Backend.cpp
+++ kdecore/auth/backends/polkit-1/Polkit1Backend.cpp
@@ -144,7 +144,7 @@
 
 Action::AuthStatus Polkit1Backend::actionStatus(const QString &action)
 {
-    PolkitQt1::UnixProcessSubject subject(QCoreApplication::applicationPid());
+    PolkitQt1::SystemBusNameSubject subject(QString::fromUtf8(callerID()));
     PolkitQt1::Authority::Result r = PolkitQt1::Authority::instance()->checkAuthorizationSync(action, subject,
                                                                                               PolkitQt1::Authority::None);
     switch (r) {
@@ -160,21 +160,12 @@
 
 QByteArray Polkit1Backend::callerID() const
 {
-    QByteArray a;
-    QDataStream s(&a, QIODevice::WriteOnly);
-    s << QCoreApplication::applicationPid();
-
-    return a;
+    return QDBusConnection::systemBus().baseService().toUtf8();
 }
 
 bool Polkit1Backend::isCallerAuthorized(const QString &action, QByteArray callerID)
 {
-    QDataStream s(&callerID, QIODevice::ReadOnly);
-    qint64 pid;
-
-    s >> pid;
-
-    PolkitQt1::UnixProcessSubject subject(pid);
+    PolkitQt1::SystemBusNameSubject subject(QString::fromUtf8(callerID));
     PolkitQt1::Authority *authority = PolkitQt1::Authority::instance();
 
     PolkitResultEventLoop e;

