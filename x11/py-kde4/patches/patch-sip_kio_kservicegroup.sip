$NetBSD: patch-sip_kio_kservicegroup.sip,v 1.1 2018/01/17 19:21:20 markd Exp $

build with sip 4.19 

--- sip/kio/kservicegroup.sip.orig	2014-08-14 20:17:11.000000000 +0000
+++ sip/kio/kservicegroup.sip
@@ -151,7 +151,7 @@ public:
         KServiceGroup::SPtr *t = new KServiceGroup::SPtr (sipCpp->at(i));
         PyObject *tobj;
 
-        if ((tobj = sipConvertFromNewInstance(t->data(), sipClass_KServiceGroup, sipTransferObj)) == NULL)
+        if ((tobj = sipConvertFromNewType(t->data(), sipType_KServiceGroup, sipTransferObj)) == NULL)
         {
             Py_DECREF(l);
             delete t;
@@ -173,7 +173,7 @@ public:
             return 0;
 
         for (int i = 0; i < PyList_GET_SIZE(sipPy); ++i)
-            if (!sipCanConvertToInstance(PyList_GET_ITEM(sipPy, i), sipClass_KServiceGroup, SIP_NOT_NONE))
+            if (!sipCanConvertToType(PyList_GET_ITEM(sipPy, i), sipType_KServiceGroup, SIP_NOT_NONE))
                 return 0;
 
         return 1;
@@ -184,11 +184,11 @@ public:
     for (int i = 0; i < PyList_GET_SIZE(sipPy); ++i)
     {
         int state;
-        KServiceGroup *t = reinterpret_cast<KServiceGroup *>(sipConvertToInstance(PyList_GET_ITEM(sipPy, i), sipClass_KServiceGroup, sipTransferObj, SIP_NOT_NONE, &state, sipIsErr));
+        KServiceGroup *t = reinterpret_cast<KServiceGroup *>(sipConvertToType(PyList_GET_ITEM(sipPy, i), sipType_KServiceGroup, sipTransferObj, SIP_NOT_NONE, &state, sipIsErr));
  
         if (*sipIsErr)
         {
-            sipReleaseInstance(t, sipClass_KServiceGroup, state);
+            sipReleaseType(t, sipType_KServiceGroup, state);
 
             delete ql;
             return 0;
@@ -198,7 +198,7 @@ public:
 
         ql->append(*tptr);
 
-        sipReleaseInstance(t, sipClass_KServiceGroup, state);
+        sipReleaseType(t, sipType_KServiceGroup, state);
     }
  
     *sipCppPtr = ql;
