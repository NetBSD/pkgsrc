$NetBSD: patch-QtTest_sipQtTestQTest.cpp,v 1.1 2018/06/23 11:23:46 wiz Exp $

Fix build with Qt 5.11, where QTest::waitForEvents was removed.

--- QtTest/sipQtTestQTest.cpp.orig	2018-06-23 09:55:45.858337471 +0000
+++ QtTest/sipQtTestQTest.cpp
@@ -265,31 +265,6 @@ static PyObject *meth_QTest_qWait(PyObje
 }
 
 
-PyDoc_STRVAR(doc_QTest_waitForEvents, "waitForEvents()");
-
-extern "C" {static PyObject *meth_QTest_waitForEvents(PyObject *, PyObject *);}
-static PyObject *meth_QTest_waitForEvents(PyObject *, PyObject *sipArgs)
-{
-    PyObject *sipParseErr = NULL;
-
-    {
-        if (sipParseArgs(&sipParseErr, sipArgs, ""))
-        {
-            Py_BEGIN_ALLOW_THREADS
-             ::QTest::waitForEvents();
-            Py_END_ALLOW_THREADS
-
-            Py_INCREF(Py_None);
-            return Py_None;
-        }
-    }
-
-    /* Raise an exception if the arguments couldn't be parsed. */
-    sipNoFunction(sipParseErr, sipName_waitForEvents, doc_QTest_waitForEvents);
-
-    return NULL;
-}
-
 
 PyDoc_STRVAR(doc_QTest_mouseEvent, "mouseEvent(QTest.MouseAction, QWidget, Qt.MouseButton, Union[Qt.KeyboardModifiers, Qt.KeyboardModifier], QPoint, delay: int = -1)\n"
 "mouseEvent(QTest.MouseAction, QWindow, Qt.MouseButton, Union[Qt.KeyboardModifiers, Qt.KeyboardModifier], QPoint, delay: int = -1)");
@@ -1311,7 +1286,6 @@ static PyMethodDef methods_QTest[] = {
     {SIP_MLNAME_CAST(sipName_qWaitForWindowActive), (PyCFunction)meth_QTest_qWaitForWindowActive, METH_VARARGS|METH_KEYWORDS, SIP_MLDOC_CAST(doc_QTest_qWaitForWindowActive)},
     {SIP_MLNAME_CAST(sipName_qWaitForWindowExposed), (PyCFunction)meth_QTest_qWaitForWindowExposed, METH_VARARGS|METH_KEYWORDS, SIP_MLDOC_CAST(doc_QTest_qWaitForWindowExposed)},
     {SIP_MLNAME_CAST(sipName_touchEvent), meth_QTest_touchEvent, METH_VARARGS, SIP_MLDOC_CAST(doc_QTest_touchEvent)},
-    {SIP_MLNAME_CAST(sipName_waitForEvents), meth_QTest_waitForEvents, METH_VARARGS, SIP_MLDOC_CAST(doc_QTest_waitForEvents)}
 };
 
 static sipEnumMemberDef enummembers_QTest[] = {
