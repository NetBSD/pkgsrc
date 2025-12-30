$NetBSD: patch-src_daemon_LogindDBusTypes.cpp,v 1.1 2025/12/30 04:00:09 gutteridge Exp $

As of version 0.21.0, support for ConsoleKit as a login manager in SDDM is broken.

--- src/daemon/LogindDBusTypes.cpp.orig	2025-10-04 05:07:32.881690547 +0000
+++ src/daemon/LogindDBusTypes.cpp
@@ -58,17 +58,17 @@ LogindPathInternal::LogindPathInternal()
         return;
     }
 
-    if (QDBusConnection::systemBus().interface()->isServiceRegistered(QStringLiteral("org.freedesktop.ConsoleKit"))) {
-        qDebug() << "Console kit interface found";
-        available = true;
-        serviceName = QStringLiteral("org.freedesktop.ConsoleKit");
-        managerPath = QStringLiteral("/org/freedesktop/ConsoleKit/Manager");
-        managerIfaceName = QStringLiteral("org.freedesktop.ConsoleKit.Manager"); //note this doesn't match logind
-        seatIfaceName = QStringLiteral("org.freedesktop.ConsoleKit.Seat");
-        sessionIfaceName = QStringLiteral("org.freedesktop.ConsoleKit.Session");
-        userIfaceName = QStringLiteral("org.freedesktop.ConsoleKit.User");
-        return;
-    }
+    //if (QDBusConnection::systemBus().interface()->isServiceRegistered(QStringLiteral("org.freedesktop.ConsoleKit"))) {
+    //    qDebug() << "Console kit interface found";
+    //    available = true;
+    //    serviceName = QStringLiteral("org.freedesktop.ConsoleKit");
+    //    managerPath = QStringLiteral("/org/freedesktop/ConsoleKit/Manager");
+    //    managerIfaceName = QStringLiteral("org.freedesktop.ConsoleKit.Manager"); //note this doesn't match logind
+    //    seatIfaceName = QStringLiteral("org.freedesktop.ConsoleKit.Seat");
+    //    sessionIfaceName = QStringLiteral("org.freedesktop.ConsoleKit.Session");
+    //    userIfaceName = QStringLiteral("org.freedesktop.ConsoleKit.User");
+    //    return;
+    //}
     qDebug() << "No session manager found";
 }
 
