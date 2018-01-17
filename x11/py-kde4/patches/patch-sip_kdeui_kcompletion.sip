$NetBSD: patch-sip_kdeui_kcompletion.sip,v 1.1 2018/01/17 19:21:20 markd Exp $

build with sip 4.19 

--- sip/kdeui/kcompletion.sip.orig	2014-08-14 20:17:11.000000000 +0000
+++ sip/kdeui/kcompletion.sip
@@ -176,7 +176,7 @@ public:
 #else
         PyObject *kobj = PyInt_FromLong((int)i.key());
 #endif
-        PyObject *tobj = sipConvertFromNewInstance(t, sipClass_KShortcut, sipTransferObj);
+        PyObject *tobj = sipConvertFromNewType(t, sipType_KShortcut, sipTransferObj);
 
         if (kobj == NULL || tobj == NULL || PyDict_SetItem(d, kobj, tobj) < 0)
         {
@@ -213,7 +213,7 @@ public:
             return 0;
 
         while (PyDict_Next(sipPy, &i, &kobj, &tobj))
-            if (!sipCanConvertToInstance(tobj, sipClass_KShortcut, SIP_NOT_NONE))
+            if (!sipCanConvertToType(tobj, sipType_KShortcut, SIP_NOT_NONE))
                 return 0;
 
         return 1;
@@ -229,11 +229,11 @@ public:
 #else
         int k = PyInt_AsLong(kobj);
 #endif
-        KShortcut *t = reinterpret_cast<KShortcut *>(sipConvertToInstance(tobj, sipClass_KShortcut, sipTransferObj, SIP_NOT_NONE, &state, sipIsErr));
+        KShortcut *t = reinterpret_cast<KShortcut *>(sipConvertToType(tobj, sipType_KShortcut, sipTransferObj, SIP_NOT_NONE, &state, sipIsErr));
  
         if (*sipIsErr)
         {
-            sipReleaseInstance(t, sipClass_KShortcut, state);
+            sipReleaseType(t, sipType_KShortcut, state);
 
             delete qm;
             return 0;
@@ -241,7 +241,7 @@ public:
 
         qm->insert((KCompletionBase::KeyBindingType)k, *t);
 
-        sipReleaseInstance(t, sipClass_KShortcut, state);
+        sipReleaseType(t, sipType_KShortcut, state);
     }
  
     *sipCppPtr = qm;
