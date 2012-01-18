$NetBSD: patch-kio_kio_scheduler.cpp,v 1.1 2012/01/18 22:03:24 abs Exp $

--- kio/kio/scheduler.cpp.orig	2010-07-07 17:08:31.000000000 +0000
+++ kio/kio/scheduler.cpp
@@ -865,6 +865,36 @@ void Scheduler::emitReparseSlaveConfigur
     emit self()->reparseSlaveConfiguration( QString() );
 }
 
+void Scheduler::slotSlaveDied(Slave* slave)
+{
+    schedulerPrivate->slotSlaveDied(slave);
+}
+
+void Scheduler::slotSlaveStatus(pid_t pid, const QByteArray& protocol, const QString& host, bool connected)
+{
+    schedulerPrivate->slotSlaveStatus(pid, protocol, host, connected);
+}
+
+void Scheduler::slotReparseSlaveConfiguration(const QString& prot)
+{
+    schedulerPrivate->slotReparseSlaveConfiguration(prot);
+}
+
+void Scheduler::slotSlaveConnected()
+{
+    schedulerPrivate->slotSlaveConnected();
+}
+
+void Scheduler::slotSlaveError(int error, const QString& errorMsg)
+{
+    schedulerPrivate->slotSlaveError(error, errorMsg);
+}
+
+void Scheduler::slotUnregisterWindow(QObject* obj)
+{
+    schedulerPrivate->slotUnregisterWindow(obj);
+}
+
 
 void SchedulerPrivate::slotReparseSlaveConfiguration(const QString &proto)
 {
