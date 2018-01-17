$NetBSD: patch-sip_kdeui_kxmlguibuilder.sip,v 1.1 2018/01/17 19:21:20 markd Exp $

build with sip 4.19 

--- sip/kdeui/kxmlguibuilder.sip.orig	2014-08-14 20:17:11.000000000 +0000
+++ sip/kdeui/kxmlguibuilder.sip
@@ -49,10 +49,10 @@ QAction *containerAction;
     PyObject *pyWidget;
     PyObject *pyContainerAction;
 
-    if ((pyWidget = sipConvertFromNewInstance(res, sipClass_QWidget, NULL)) == NULL)
+    if ((pyWidget = sipConvertFromNewType(res, sipType_QWidget, NULL)) == NULL)
         return NULL;
 
-    if ((pyContainerAction = sipConvertFromNewInstance(containerAction, sipClass_QAction, NULL)) == NULL)
+    if ((pyContainerAction = sipConvertFromNewType(containerAction, sipType_QAction, NULL)) == NULL)
         return NULL;
 
     sipRes = Py_BuildValue ("NN", pyWidget, pyContainerAction);
