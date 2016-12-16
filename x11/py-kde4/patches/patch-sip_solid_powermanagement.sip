$NetBSD: patch-sip_solid_powermanagement.sip,v 1.1 2016/12/16 00:04:54 joerg Exp $

--- sip/solid/powermanagement.sip.orig	2016-12-15 12:53:38.625458181 +0000
+++ sip/solid/powermanagement.sip
@@ -83,7 +83,7 @@ bool                    stopSuppressingS
 #else
         PyObject *obj = PyInt_FromLong ((long) value);
 #endif
-        if (obj == NULL || PyList_SET_ITEM (l, i, obj) < 0)
+        if (obj == NULL)
         {
             Py_DECREF(l);
 
@@ -92,7 +92,7 @@ bool                    stopSuppressingS
 
             return NULL;
         }
-
+        PyList_SET_ITEM (l, i, obj);
         Py_DECREF(obj);
         i++;
     }
