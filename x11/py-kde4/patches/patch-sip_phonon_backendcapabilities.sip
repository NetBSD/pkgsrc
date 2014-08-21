$NetBSD: patch-sip_phonon_backendcapabilities.sip,v 1.1 2014/08/21 21:34:33 wiz Exp $

--- sip/phonon/backendcapabilities.sip.orig	2014-01-02 19:29:04.000000000 +0000
+++ sip/phonon/backendcapabilities.sip
@@ -26,15 +26,28 @@ namespace Phonon
 {
 namespace BackendCapabilities
 {
+
+// SIP 4.16 renamed the PyQt4NoQMetaObject annotation to PyQtNoQMetaObject.
+// Since SIP does not have a preprocessor, we have to duplicate the class
+// definition with different annotations.
+%If (SIP_4_16 - )
+class Notifier : QObject /NoDefaultCtors,PyQtNoQMetaObject/
+{
+signals:
+    void                    capabilitiesChanged ();
+    void                    availableAudioOutputDevicesChanged ();
+    void                    availableAudioCaptureDevicesChanged ();
+};
+%End
+%If ( - SIP_4_16)
 class Notifier : QObject /NoDefaultCtors,PyQt4NoQMetaObject/
 {
-
 signals:
     void                    capabilitiesChanged ();
     void                    availableAudioOutputDevicesChanged ();
     void                    availableAudioCaptureDevicesChanged ();
 };
-// Notifier
+%End
 
 Phonon::BackendCapabilities::Notifier*  notifier ();
 QStringList             availableMimeTypes ();
