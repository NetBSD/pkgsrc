$NetBSD: patch-sip_phonon_objectdescription.sip,v 1.1 2018/01/17 19:21:20 markd Exp $

build with sip 4.19 

--- sip/phonon/objectdescription.sip.orig	2014-08-14 20:17:11.000000000 +0000
+++ sip/phonon/objectdescription.sip
@@ -116,7 +116,7 @@ void                    registerMetaType
         DNSSD::RemoteService::Ptr *t = new Phonon::ObjectDescription (sipCpp->at(i));
         PyObject *tobj;
 
-        if ((tobj = sipConvertFromNewInstance(t->data(), sipClass_DNSSD_RemoteService, sipTransferObj)) == NULL)
+        if ((tobj = sipConvertFromNewType(t->data(), sipType_DNSSD_RemoteService, sipTransferObj)) == NULL)
         {
             Py_DECREF(l);
             delete t;
@@ -138,7 +138,7 @@ void                    registerMetaType
             return 0;
 
         for (int i = 0; i < PyList_GET_SIZE(sipPy); ++i)
-            if (!sipCanConvertToInstance(PyList_GET_ITEM(sipPy, i), sipClass_DNSSD_RemoteService, SIP_NOT_NONE))
+            if (!sipCanConvertToType(PyList_GET_ITEM(sipPy, i), sipType_DNSSD_RemoteService, SIP_NOT_NONE))
                 return 0;
 
         return 1;
@@ -149,11 +149,11 @@ void                    registerMetaType
     for (int i = 0; i < PyList_GET_SIZE(sipPy); ++i)
     {
         int state;
-        DNSSD::RemoteService *t = reinterpret_cast<DNSSD::RemoteService *>(sipConvertToInstance(PyList_GET_ITEM(sipPy, i), sipClass_DNSSD_RemoteService, sipTransferObj, SIP_NOT_NONE, &state, sipIsErr));
+        DNSSD::RemoteService *t = reinterpret_cast<DNSSD::RemoteService *>(sipConvertToType(PyList_GET_ITEM(sipPy, i), sipType_DNSSD_RemoteService, sipTransferObj, SIP_NOT_NONE, &state, sipIsErr));
  
         if (*sipIsErr)
         {
-            sipReleaseInstance(t, sipClass_DNSSD_RemoteService, state);
+            sipReleaseType(t, sipType_DNSSD_RemoteService, state);
 
             delete ql;
             return 0;
@@ -163,7 +163,7 @@ void                    registerMetaType
 
         ql->append(*tptr);
 
-        sipReleaseInstance(t, sipClass_DNSSD_RemoteService, state);
+        sipReleaseType(t, sipType_DNSSD_RemoteService, state);
     }
  
     *sipCppPtr = ql;
