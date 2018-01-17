$NetBSD: patch-sip_dnssd_remoteservice.sip,v 1.1 2018/01/17 19:21:20 markd Exp $

build with sip 4.19

--- sip/dnssd/remoteservice.sip.orig	2014-08-14 20:17:11.000000000 +0000
+++ sip/dnssd/remoteservice.sip
@@ -66,7 +66,7 @@ protected:
         DNSSD::RemoteService::Ptr *t = new DNSSD::RemoteService::Ptr (sipCpp->at(i));
         PyObject *tobj;
 
-        if ((tobj = sipConvertFromNewInstance(t->data(), sipClass_DNSSD_RemoteService, sipTransferObj)) == NULL)
+        if ((tobj = sipConvertFromNewType(t->data(), sipType_DNSSD_RemoteService, sipTransferObj)) == NULL)
         {
             Py_DECREF(l);
             delete t;
@@ -88,7 +88,7 @@ protected:
             return 0;
 
         for (int i = 0; i < PyList_GET_SIZE(sipPy); ++i)
-            if (!sipCanConvertToInstance(PyList_GET_ITEM(sipPy, i), sipClass_DNSSD_RemoteService, SIP_NOT_NONE))
+            if (!sipCanConvertToType(PyList_GET_ITEM(sipPy, i), sipType_DNSSD_RemoteService, SIP_NOT_NONE))
                 return 0;
 
         return 1;
@@ -99,11 +99,11 @@ protected:
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
@@ -113,7 +113,7 @@ protected:
 
         ql->append(*tptr);
 
-        sipReleaseInstance(t, sipClass_DNSSD_RemoteService, state);
+        sipReleaseType(t, sipType_DNSSD_RemoteService, state);
     }
  
     *sipCppPtr = ql;
