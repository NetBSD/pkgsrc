$NetBSD: patch-sip_solid_predicate.sip,v 1.1 2016/12/16 00:04:54 joerg Exp $

--- sip/solid/predicate.sip.orig	2016-12-15 12:52:41.763919370 +0000
+++ sip/solid/predicate.sip
@@ -112,7 +112,7 @@ Py_BEGIN_ALLOW_THREADS
 #else
         PyObject *obj = PyInt_FromLong ((long) value);
 #endif
-        if (obj == NULL || PyList_SET_ITEM (l, i, obj) < 0)
+        if (obj == NULL)
         {
             Py_DECREF(l);
 
@@ -121,7 +121,7 @@ Py_BEGIN_ALLOW_THREADS
 
             return NULL;
         }
-
+        PyList_SET_ITEM (l, i, obj);
         Py_DECREF(obj);
         i++;
     }
