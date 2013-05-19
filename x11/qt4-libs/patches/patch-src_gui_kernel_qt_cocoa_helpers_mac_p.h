$NetBSD: patch-src_gui_kernel_qt_cocoa_helpers_mac_p.h,v 1.1 2013/05/19 09:10:10 adam Exp $

Fix building on Mac OS X.

--- src/gui/kernel/qt_cocoa_helpers_mac_p.h.orig	2013-05-19 08:02:18.000000000 +0000
+++ src/gui/kernel/qt_cocoa_helpers_mac_p.h
@@ -155,7 +155,7 @@ bool qt_dispatchKeyEvent(void * /*NSEven
 void qt_dispatchModifiersChanged(void * /*NSEvent * */flagsChangedEvent, QWidget *widgetToGetEvent);
 bool qt_mac_handleTabletEvent(void * /*QCocoaView * */view, void * /*NSEvent * */event);
 inline QApplication *qAppInstance() { return static_cast<QApplication *>(QCoreApplication::instance()); }
-struct ::TabletProximityRec;
+struct TabletProximityRec;
 void qt_dispatchTabletProximityEvent(const ::TabletProximityRec &proxRec);
 Qt::KeyboardModifiers qt_cocoaModifiers2QtModifiers(ulong modifierFlags);
 Qt::KeyboardModifiers qt_cocoaDragOperation2QtModifiers(uint dragOperations);
