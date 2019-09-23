$NetBSD: patch-sip_kdecore_typedefs.sip,v 1.4 2019/09/23 21:55:43 mef Exp $

build with sip 4.19 
build with sip 4.19.18 (size_t issue) 

--- sip/kdecore/typedefs.sip.orig	2014-08-15 05:17:11.000000000 +0900
+++ sip/kdecore/typedefs.sip	2019-09-16 10:32:45.923750123 +0900
@@ -23,8 +23,6 @@ typedef uint mode_t;
 
 typedef long time_t;
 
-typedef ulong size_t;
-
 typedef int ssize_t;
 
 typedef int pid_t;
@@ -397,8 +395,8 @@ template <TYPE1,TYPE2>
         TYPE1 *t1 = new TYPE1(i.key());
         TYPE2 *t2 = new TYPE2(i.value());
 
-        PyObject *t1obj = sipConvertFromNewInstance(t1, sipClass_TYPE1, sipTransferObj);
-        PyObject *t2obj = sipConvertFromNewInstance(t2, sipClass_TYPE2, sipTransferObj);
+        PyObject *t1obj = sipConvertFromNewType(t1, sipType_TYPE1, sipTransferObj);
+        PyObject *t2obj = sipConvertFromNewType(t2, sipType_TYPE2, sipTransferObj);
 
         if (t1obj == NULL || t2obj == NULL || PyDict_SetItem(d, t1obj, t2obj) < 0)
         {
@@ -438,10 +438,10 @@ template <TYPE1,TYPE2>
 
         while (PyDict_Next(sipPy, &i, &t1obj, &t2obj))
         {
-            if (!sipCanConvertToInstance(t1obj, sipClass_TYPE1, SIP_NOT_NONE))
+            if (!sipCanConvertToType(t1obj, sipType_TYPE1, SIP_NOT_NONE))
                 return 0;
 
-            if (!sipCanConvertToInstance(t2obj, sipClass_TYPE2, SIP_NOT_NONE))
+            if (!sipCanConvertToType(t2obj, sipType_TYPE2, SIP_NOT_NONE))
                 return 0;
         } 
 
@@ -454,13 +454,13 @@ template <TYPE1,TYPE2>
     {
         int state1, state2;
 
-        TYPE1 *t1 = reinterpret_cast<TYPE1 *>(sipConvertToInstance(t1obj, sipClass_TYPE1, sipTransferObj, SIP_NOT_NONE, &state1, sipIsErr));
-        TYPE2 *t2 = reinterpret_cast<TYPE2 *>(sipConvertToInstance(t2obj, sipClass_TYPE2, sipTransferObj, SIP_NOT_NONE, &state2, sipIsErr));
+        TYPE1 *t1 = reinterpret_cast<TYPE1 *>(sipConvertToType(t1obj, sipType_TYPE1, sipTransferObj, SIP_NOT_NONE, &state1, sipIsErr));
+        TYPE2 *t2 = reinterpret_cast<TYPE2 *>(sipConvertToType(t2obj, sipType_TYPE2, sipTransferObj, SIP_NOT_NONE, &state2, sipIsErr));
  
         if (*sipIsErr)
         {
-            sipReleaseInstance(t1, sipClass_TYPE1, state1);
-            sipReleaseInstance(t2, sipClass_TYPE2, state2);
+            sipReleaseType(t1, sipType_TYPE1, state1);
+            sipReleaseType(t2, sipType_TYPE2, state2);
 
             delete qm;
             return 0;
@@ -468,8 +468,8 @@ template <TYPE1,TYPE2>
 
         qm->insert(*t1, *t2);
 
-        sipReleaseInstance(t1, sipClass_TYPE1, state1);
-        sipReleaseInstance(t2, sipClass_TYPE2, state2);
+        sipReleaseType(t1, sipType_TYPE1, state1);
+        sipReleaseType(t2, sipType_TYPE2, state2);
     }
  
     *sipCppPtr = qm;
@@ -669,7 +669,7 @@ template <TYPE*>
         TYPE *t = (TYPE *)(sipCpp->at(i));
         PyObject *tobj;
 
-        if ((tobj = sipConvertFromNewInstance(t, sipClass_TYPE, sipTransferObj)) == NULL)
+        if ((tobj = sipConvertFromNewType(t, sipType_TYPE, sipTransferObj)) == NULL)
         {
             Py_DECREF(l);
             delete t;
@@ -691,7 +691,7 @@ template <TYPE*>
             return 0;
 
         for (int i = 0; i < PyList_GET_SIZE(sipPy); ++i)
-            if (!sipCanConvertToInstance(PyList_GET_ITEM(sipPy, i), sipClass_TYPE, SIP_NOT_NONE))
+            if (!sipCanConvertToType(PyList_GET_ITEM(sipPy, i), sipType_TYPE, SIP_NOT_NONE))
                 return 0;
 
         return 1;
@@ -702,11 +702,11 @@ template <TYPE*>
     for (int i = 0; i < PyList_GET_SIZE(sipPy); ++i)
     {
         int state;
-        TYPE *t = reinterpret_cast<TYPE *>(sipConvertToInstance(PyList_GET_ITEM(sipPy, i), sipClass_TYPE, sipTransferObj, SIP_NOT_NONE, &state, sipIsErr));
+        TYPE *t = reinterpret_cast<TYPE *>(sipConvertToType(PyList_GET_ITEM(sipPy, i), sipType_TYPE, sipTransferObj, SIP_NOT_NONE, &state, sipIsErr));
  
         if (*sipIsErr)
         {
-            sipReleaseInstance(t, sipClass_TYPE, state);
+            sipReleaseType(t, sipType_TYPE, state);
 
             delete qv;
             return 0;
@@ -714,7 +714,7 @@ template <TYPE*>
 
         qv->append(t);
 
-        sipReleaseInstance(t, sipClass_TYPE, state);
+        sipReleaseType(t, sipType_TYPE, state);
     }
  
     *sipCppPtr = qv;
@@ -1028,4 +1026,4 @@ template <TYPE1>
     return sipGetState(sipTransferObj);
 %End
 };
-%End
\ No newline at end of file
+%End
