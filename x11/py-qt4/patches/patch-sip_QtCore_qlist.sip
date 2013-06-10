$NetBSD: patch-sip_QtCore_qlist.sip,v 1.1 2013/06/10 15:37:36 jperkin Exp $

Implement QList<long> for SunOS 32-bit pid_t.

--- sip/QtCore/qlist.sip.orig	2013-04-21 12:02:19.000000000 +0000
+++ sip/QtCore/qlist.sip
@@ -683,6 +683,68 @@ template<qreal, TYPE>
     return sipGetState(sipTransferObj);
 %End
 };
+// QList<long> is implemented as a Python list of integers.
+%MappedType QList<long> /DocType="list-of-long"/
+{
+%TypeHeaderCode
+#include <qlist.h>
+%End
+
+%ConvertFromTypeCode
+    // Create the list.
+    PyObject *l;
+
+    if ((l = PyList_New(sipCpp->size())) == NULL)
+        return NULL;
+
+    // Set the list elements.
+    for (int i = 0; i < sipCpp->size(); ++i)
+    {
+        PyObject *pobj;
+
+        if ((pobj = SIPLong_FromLong(sipCpp->value(i))) == NULL)
+        {
+            Py_DECREF(l);
+
+            return NULL;
+        }
+
+        PyList_SET_ITEM(l, i, pobj);
+    }
+
+    return l;
+%End
+
+%ConvertToTypeCode
+    // Check the type if that is all that is required.
+    if (sipIsErr == NULL)
+        return (PySequence_Check(sipPy) && PySequence_Size(sipPy) >= 0);
+
+    QList<long> *ql = new QList<long>;
+    SIP_SSIZE_T len = PySequence_Size(sipPy);
+ 
+    for (SIP_SSIZE_T i = 0; i < len; ++i)
+    {
+        PyObject *itm = PySequence_ITEM(sipPy, i);
+
+        if (!itm)
+        {
+            delete ql;
+            *sipIsErr = 1;
+
+            return 0;
+        }
+
+        ql->append(SIPLong_AsLong(itm));
+
+        Py_DECREF(itm);
+    }
+ 
+    *sipCppPtr = ql;
+ 
+    return sipGetState(sipTransferObj);
+%End
+};
 // QList<unsigned> is implemented as a Python list of unsigned longs.
 %MappedType QList<unsigned> /DocType="list-of-int"/
 {
