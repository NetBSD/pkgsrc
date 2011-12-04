$NetBSD: patch-python_neo__cgi.c,v 1.1.2.2 2011/12/04 22:23:04 sbd Exp $

Fix for 2011-4357
Taken from: http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=649322

--- python/neo_cgi.c.orig	2007-07-12 03:07:43.000000000 +0000
+++ python/neo_cgi.c
@@ -178,7 +178,7 @@ static PyObject * p_cgi_error (PyObject 
   if (!PyArg_ParseTuple(args, "s:error(str)", &s))
     return NULL;
 
-  cgi_error (cgi, s);
+  cgi_error (cgi, "%s", s);
   rv = Py_None;
   Py_INCREF(rv);
   return rv;
