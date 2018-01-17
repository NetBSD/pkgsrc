$NetBSD: patch-sip_kdecore_ksharedconfig.sip,v 1.1 2018/01/17 19:21:20 markd Exp $

build with sip 4.19 

--- sip/kdecore/ksharedconfig.sip.orig	2014-08-14 20:17:11.000000000 +0000
+++ sip/kdecore/ksharedconfig.sip
@@ -65,7 +65,7 @@ typedef KSharedConfig::Ptr KSharedConfig
     KSharedConfigPtr kcpp = *sipCpp;
     KSharedConfig *ksc    = kcpp.data ();
     ksc->ref.ref();
-    PyObject *pyKsc       = sipConvertFromInstance(ksc, sipClass_KSharedConfig, sipTransferObj);
+    PyObject *pyKsc       = sipConvertFromType(ksc, sipType_KSharedConfig, sipTransferObj);
     return pyKsc;
 %End
 
@@ -74,7 +74,7 @@ typedef KSharedConfig::Ptr KSharedConfig
         return 1;
 
     int state;
-    KSharedConfig* ksc = (KSharedConfig *)sipConvertToInstance(sipPy, sipClass_KSharedConfig, sipTransferObj, SIP_NOT_NONE, &state, sipIsErr);
+    KSharedConfig* ksc = (KSharedConfig *)sipConvertToType(sipPy, sipType_KSharedConfig, sipTransferObj, SIP_NOT_NONE, &state, sipIsErr);
     *sipCppPtr = new KSharedConfigPtr (ksc);
     ksc->ref.deref();
     return sipGetState(sipTransferObj);
