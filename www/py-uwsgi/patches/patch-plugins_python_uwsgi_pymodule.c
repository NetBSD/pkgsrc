$NetBSD: patch-plugins_python_uwsgi_pymodule.c,v 1.1 2011/04/08 12:26:29 adam Exp $

Fix compiler errors.

--- plugins/python/uwsgi_pymodule.c.orig	2011-04-08 09:58:04.000000000 +0000
+++ plugins/python/uwsgi_pymodule.c
@@ -343,7 +343,7 @@ PyObject *py_uwsgi_rpc(PyObject * self, 
 		argv[i] = PyString_AsString(PyTuple_GetItem(args, i + 2));
 	}
 
-	if (node == (char *) "") {
+	if (node[0] == '\0') {
 		size = uwsgi_rpc(func, 0, NULL, buffer);
 	}
 	else {
@@ -2662,7 +2662,7 @@ PyObject *py_uwsgi_queue_last(PyObject *
 PyObject *py_uwsgi_cache_get(PyObject * self, PyObject * args) {
 
 	char *key;
-	uint64_t valsize;
+	uint64_t valsize = 0;
 	Py_ssize_t keylen = 0;
 	char *value = NULL;
 	char *remote = NULL;
