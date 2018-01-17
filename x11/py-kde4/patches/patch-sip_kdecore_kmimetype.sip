$NetBSD: patch-sip_kdecore_kmimetype.sip,v 1.1 2018/01/17 19:21:20 markd Exp $

build with sip 4.19 

--- sip/kdecore/kmimetype.sip.orig	2014-08-14 20:17:11.000000000 +0000
+++ sip/kdecore/kmimetype.sip
@@ -100,7 +100,7 @@ public:
         KMimeType::Ptr *t = new KMimeType::Ptr (sipCpp->at(i));
         PyObject *tobj;
 
-        if ((tobj = sipConvertFromNewInstance(t->data(), sipClass_KMimeType, sipTransferObj)) == NULL)
+        if ((tobj = sipConvertFromNewType(t->data(), sipType_KMimeType, sipTransferObj)) == NULL)
         {
             Py_DECREF(l);
             delete t;
@@ -122,7 +122,7 @@ public:
             return 0;
 
         for (int i = 0; i < PyList_GET_SIZE(sipPy); ++i)
-            if (!sipCanConvertToInstance(PyList_GET_ITEM(sipPy, i), sipClass_KMimeType, SIP_NOT_NONE))
+            if (!sipCanConvertToType(PyList_GET_ITEM(sipPy, i), sipType_KMimeType, SIP_NOT_NONE))
                 return 0;
 
         return 1;
@@ -133,11 +133,11 @@ public:
     for (int i = 0; i < PyList_GET_SIZE(sipPy); ++i)
     {
         int state;
-        KMimeType *t = reinterpret_cast<KMimeType *>(sipConvertToInstance(PyList_GET_ITEM(sipPy, i), sipClass_KMimeType, sipTransferObj, SIP_NOT_NONE, &state, sipIsErr));
+        KMimeType *t = reinterpret_cast<KMimeType *>(sipConvertToType(PyList_GET_ITEM(sipPy, i), sipType_KMimeType, sipTransferObj, SIP_NOT_NONE, &state, sipIsErr));
  
         if (*sipIsErr)
         {
-            sipReleaseInstance(t, sipClass_KMimeType, state);
+            sipReleaseType(t, sipType_KMimeType, state);
 
             delete ql;
             return 0;
@@ -147,7 +147,7 @@ public:
 
         ql->append(*tptr);
 
-        sipReleaseInstance(t, sipClass_KMimeType, state);
+        sipReleaseType(t, sipType_KMimeType, state);
     }
  
     *sipCppPtr = ql;
