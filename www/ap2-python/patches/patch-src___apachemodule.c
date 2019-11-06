$NetBSD: patch-src___apachemodule.c,v 1.1 2019/11/06 16:49:48 martin Exp $

Add support for python 3.7, based on
https://github.com/grisha/mod_python/pull/80/commits/8fb45feab94152a6aae3492aed4b81c363a912bd

--- src/_apachemodule.c.orig	2019-11-06 16:27:40.549245378 +0100
+++ src/_apachemodule.c	2019-11-06 16:27:44.529287280 +0100
@@ -851,8 +851,13 @@ PyObject *_apache_module_init()
 #else
     m = PyModule_Create(&_apache_moduledef);
     PyObject *name = PyUnicode_FromString("_apache");
+#if PY_MINOR_VERSION >= 7
+    PyObject *modules = PyImport_GetModuleDict();
+    _PyImport_FixupExtensionObject(m, name, name, modules);
+#else
     _PyImport_FixupExtensionObject(m, name, name);
 #endif
+#endif
     d = PyModule_GetDict(m);
     Mp_ServerReturn = PyErr_NewException("_apache.SERVER_RETURN", NULL, NULL);
     if (Mp_ServerReturn == NULL)
