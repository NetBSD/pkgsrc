$NetBSD: patch-sip_kdecore_typedefs.sip,v 1.1 2012/10/11 13:17:09 wiz Exp $

py-qt4 defines this itself since about 4.9.5; avoid conflict.

--- sip/kdecore/typedefs.sip.orig	2011-07-27 18:37:15.000000000 +0000
+++ sip/kdecore/typedefs.sip
@@ -951,77 +951,3 @@ template <TYPE1>
 %End
 };
 
-%MappedType QVector<int>
-{
-%TypeHeaderCode
-#include <qvector.h>
-%End
-
-%ConvertFromTypeCode
-    // Create the list.
-    PyObject *l;
-
-    if ((l = PyList_New(sipCpp->size())) == NULL)
-        return NULL;
-
-    // Set the list elements.
-    for (int i = 0; i < sipCpp->size(); ++i)
-    {
-        int t = (sipCpp->at(i));
-
-#if PY_MAJOR_VERSION >= 3        
-        PyObject *tobj = PyLong_FromLong(t);
-#else
-        PyObject *tobj = PyInt_FromLong(t);
-#endif
-
-        PyList_SET_ITEM(l, i, tobj);
-    }
-
-    return l;
-%End
-
-%ConvertToTypeCode
-    // Check the type if that is all that is required.
-    if (sipIsErr == NULL)
-    {
-        if (!PyList_Check(sipPy))
-            return 0;
-
-        for (int i = 0; i < PyList_GET_SIZE(sipPy); ++i) {
-            PyObject *tobj = PyList_GET_ITEM(sipPy, i);
-#if PY_MAJOR_VERSION >= 3
-            if (!PyNumber_Check(tobj))
-#else
-            if (!PyInt_Check(tobj))
-#endif
-                return 0;
-        }
-        return 1;
-    }
-
-    QVector<int> *qv = new QVector<int>;
- 
-    for (int i = 0; i < PyList_GET_SIZE(sipPy); ++i)
-    {
-        PyObject *tobj = PyList_GET_ITEM(sipPy, i);
- #if PY_MAJOR_VERSION >= 3
-        int t = PyLong_AsLong (tobj);
-#else
-        int t = PyInt_AS_LONG (tobj);
-#endif
-
-        if (*sipIsErr)
-        {
-            delete qv;
-            return 0;
-        }
-
-        qv->append(t);
-    }
- 
-    *sipCppPtr = qv;
- 
-    return sipGetState(sipTransferObj);
-%End
-};
