$NetBSD: patch-src_3rdparty_webkit_Source_WebKit_qt_WebCoreSupport_NotificationPresenterClientQt.cpp,v 1.1 2013/05/09 14:07:08 joerg Exp $

--- src/3rdparty/webkit/Source/WebKit/qt/WebCoreSupport/NotificationPresenterClientQt.cpp.orig	2013-05-03 13:43:43.000000000 +0000
+++ src/3rdparty/webkit/Source/WebKit/qt/WebCoreSupport/NotificationPresenterClientQt.cpp
@@ -73,9 +73,9 @@ NotificationWrapper::NotificationWrapper
 #if ENABLE(NOTIFICATIONS)
 
 #ifndef QT_NO_SYSTEMTRAYICON
-    m_notificationIcon = 0;
+    m_notificationIcon = nullptr;
 #endif
-    m_presenter = 0;
+    m_presenter = nullptr;
 #endif
 }
 
@@ -211,9 +211,9 @@ void NotificationPresenterClientQt::disp
         QPixmap pixmap;
         if (bytes.length() && pixmap.loadFromData(bytes)) {
             QIcon icon(pixmap);
-            wrapper->m_notificationIcon = new QSystemTrayIcon(icon);
+            wrapper->m_notificationIcon = adoptPtr(new QSystemTrayIcon(icon));
         } else
-            wrapper->m_notificationIcon = new QSystemTrayIcon();
+            wrapper->m_notificationIcon = adoptPtr(new QSystemTrayIcon());
 #endif
     }
 
