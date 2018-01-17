$NetBSD: patch-sip_kdecore_ksycocaentry.sip,v 1.1 2018/01/17 19:21:20 markd Exp $

build with sip 4.19 

--- sip/kdecore/ksycocaentry.sip.orig	2014-08-14 20:17:11.000000000 +0000
+++ sip/kdecore/ksycocaentry.sip
@@ -83,7 +83,7 @@ private:
         KSycocaEntry::Ptr *t = new KSycocaEntry::Ptr (sipCpp->at(i));
         PyObject *tobj;
 
-        if ((tobj = sipConvertFromNewInstance(t->data(), sipClass_KSycocaEntry, sipTransferObj)) == NULL)
+        if ((tobj = sipConvertFromNewType(t->data(), sipType_KSycocaEntry, sipTransferObj)) == NULL)
         {
             Py_DECREF(l);
             delete t;
@@ -105,7 +105,7 @@ private:
             return 0;
 
         for (int i = 0; i < PyList_GET_SIZE(sipPy); ++i)
-            if (!sipCanConvertToInstance(PyList_GET_ITEM(sipPy, i), sipClass_KSycocaEntry, SIP_NOT_NONE))
+            if (!sipCanConvertToType(PyList_GET_ITEM(sipPy, i), sipType_KSycocaEntry, SIP_NOT_NONE))
                 return 0;
 
         return 1;
@@ -116,11 +116,11 @@ private:
     for (int i = 0; i < PyList_GET_SIZE(sipPy); ++i)
     {
         int state;
-        KSycocaEntry *t = reinterpret_cast<KSycocaEntry *>(sipConvertToInstance(PyList_GET_ITEM(sipPy, i), sipClass_KSycocaEntry, sipTransferObj, SIP_NOT_NONE, &state, sipIsErr));
+        KSycocaEntry *t = reinterpret_cast<KSycocaEntry *>(sipConvertToType(PyList_GET_ITEM(sipPy, i), sipType_KSycocaEntry, sipTransferObj, SIP_NOT_NONE, &state, sipIsErr));
  
         if (*sipIsErr)
         {
-            sipReleaseInstance(t, sipClass_KSycocaEntry, state);
+            sipReleaseType(t, sipType_KSycocaEntry, state);
 
             delete ql;
             return 0;
@@ -130,7 +130,7 @@ private:
 
         ql->append(*tptr);
 
-        sipReleaseInstance(t, sipClass_KSycocaEntry, state);
+        sipReleaseType(t, sipType_KSycocaEntry, state);
     }
  
     *sipCppPtr = ql;
