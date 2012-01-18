$NetBSD: patch-kio_kio_scheduler.h,v 1.1 2012/01/18 22:03:24 abs Exp $

--- kio/kio/scheduler.h.orig	2010-02-03 08:50:40.000000000 +0000
+++ kio/kio/scheduler.h
@@ -29,6 +29,8 @@
 #include <QtGui/QWidgetList>
 #include <sys/types.h> // pid_t
 
+class QDBusMessage;
+
 namespace KIO {
 
     class Slave;
@@ -278,16 +280,17 @@ namespace KIO {
 
         static Scheduler *self();
 
-        Q_PRIVATE_SLOT(schedulerPrivate, void slotSlaveDied(KIO::Slave *slave))
-        Q_PRIVATE_SLOT(schedulerPrivate, void slotSlaveStatus(pid_t pid, const QByteArray &protocol,
-                                               const QString &host, bool connected))
+    private Q_SLOTS:
+        void slotSlaveDied(KIO::Slave *slave);
+        void slotSlaveStatus(pid_t pid, const QByteArray &protocol,
+                             const QString &host, bool connected);
 
         // connected to D-Bus signal:
-        Q_PRIVATE_SLOT(schedulerPrivate, void slotReparseSlaveConfiguration(const QString &))
+        void slotReparseSlaveConfiguration(const QString &);
+        void slotSlaveConnected();
+        void slotSlaveError(int error, const QString &errorMsg);
+        void slotUnregisterWindow(QObject *);
 
-        Q_PRIVATE_SLOT(schedulerPrivate, void slotSlaveConnected())
-        Q_PRIVATE_SLOT(schedulerPrivate, void slotSlaveError(int error, const QString &errorMsg))
-        Q_PRIVATE_SLOT(schedulerPrivate, void slotUnregisterWindow(QObject *))
     private:
         friend class SchedulerPrivate;
         SchedulerPrivate *const d;
