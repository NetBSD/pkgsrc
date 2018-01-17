$NetBSD: patch-sip_ktexteditor_markinterface.sip,v 1.1 2018/01/17 19:21:20 markd Exp $

build with sip 4.19 

--- sip/ktexteditor/markinterface.sip.orig	2014-08-14 20:17:11.000000000 +0000
+++ sip/ktexteditor/markinterface.sip
@@ -158,7 +158,7 @@ signals:
 #else
         PyObject *t1obj = PyInt_FromLong ((long)t1);
 #endif
-        PyObject *t2obj = sipConvertFromNewInstance(t2, sipClass_KTextEditor_Mark, sipTransferObj);
+        PyObject *t2obj = sipConvertFromNewType(t2, sipType_KTextEditor_Mark, sipTransferObj);
 
         if (t2obj == NULL || PyDict_SetItem(d, t1obj, t2obj) < 0)
         {
@@ -203,7 +203,7 @@ signals:
 #endif
                 return 0;
 
-            if (!sipCanConvertToInstance(t2obj, sipClass_KTextEditor_Mark, SIP_NOT_NONE))
+            if (!sipCanConvertToType(t2obj, sipType_KTextEditor_Mark, SIP_NOT_NONE))
                 return 0;
         } 
 
@@ -221,11 +221,11 @@ signals:
 #else
         int t1 = PyInt_AS_LONG (t1obj);
 #endif
-        KTextEditor::Mark *t2 = reinterpret_cast<KTextEditor::Mark *>(sipConvertToInstance(t2obj, sipClass_KTextEditor_Mark, sipTransferObj, SIP_NOT_NONE, &state2, sipIsErr));
+        KTextEditor::Mark *t2 = reinterpret_cast<KTextEditor::Mark *>(sipConvertToType(t2obj, sipType_KTextEditor_Mark, sipTransferObj, SIP_NOT_NONE, &state2, sipIsErr));
  
         if (*sipIsErr)
         {
-            sipReleaseInstance(t2, sipClass_KTextEditor_Mark, state2);
+            sipReleaseType(t2, sipType_KTextEditor_Mark, state2);
 
             delete qm;
             return 0;
@@ -233,7 +233,7 @@ signals:
 
         qm->insert(t1, t2);
 
-        sipReleaseInstance(t2, sipClass_KTextEditor_Mark, state2);
+        sipReleaseType(t2, sipType_KTextEditor_Mark, state2);
     }
  
     *sipCppPtr = qm;
