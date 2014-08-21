$NetBSD: patch-sip_solid_networking.sip,v 1.1 2014/08/21 21:34:33 wiz Exp $

--- sip/solid/networking.sip.orig	2014-01-02 19:29:04.000000000 +0000
+++ sip/solid/networking.sip
@@ -51,6 +51,20 @@ Solid::Networking::Status  status ();
 //ig void                    setDisconnectPolicy (Solid::Networking::ManagementPolicy policy);
 //ig Solid::Networking::ManagementPolicy  disconnectPolicy ();
 
+// SIP 4.16 renamed the PyQt4NoQMetaObject annotation to PyQtNoQMetaObject.
+// Since SIP does not have a preprocessor, we have to duplicate the class
+// definition with different annotations.
+%If (SIP_4_16 - )
+class Notifier : QObject /Abstract,PyQtNoQMetaObject/
+{
+    void                    statusChanged (Solid::Networking::Status status);
+    void                    shouldConnect ();
+    void                    shouldDisconnect ();
+protected:
+                            Notifier ();
+};
+%End
+%If ( - SIP_4_16)
 class Notifier : QObject /Abstract,PyQt4NoQMetaObject/
 {
     void                    statusChanged (Solid::Networking::Status status);
@@ -59,6 +73,7 @@ class Notifier : QObject /Abstract,PyQt4
 protected:
                             Notifier ();
 };
+%End
 
 Solid::Networking::Notifier*  notifier ();
 };
