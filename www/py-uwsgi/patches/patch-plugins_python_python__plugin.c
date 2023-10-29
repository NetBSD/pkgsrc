$NetBSD: patch-plugins_python_python__plugin.c,v 1.1 2023/10/29 18:18:03 wiz Exp $

Python 3.12 support
https://github.com/unbit/uwsgi/pull/2542

--- plugins/python/python_plugin.c.orig	2023-07-27 15:34:12.000000000 +0000
+++ plugins/python/python_plugin.c
@@ -197,6 +197,21 @@ void uwsgi_python_pthread_child(void) {
 PyMethodDef uwsgi_spit_method[] = { {"uwsgi_spit", py_uwsgi_spit, METH_VARARGS, ""} };
 PyMethodDef uwsgi_write_method[] = { {"uwsgi_write", py_uwsgi_write, METH_VARARGS, ""} };
 
+PyDoc_STRVAR(uwsgi_py_doc, "uWSGI api module.");
+
+#ifdef PYTHREE
+static PyModuleDef uwsgi_module3 = {
+	PyModuleDef_HEAD_INIT,
+	"uwsgi",
+	uwsgi_py_doc,
+	-1,
+	NULL,
+};
+PyObject *init_uwsgi3(void) {
+	return PyModule_Create(&uwsgi_module3);
+}
+#endif
+
 int uwsgi_python_init() {
 
 	char *pyversion = strchr(Py_GetVersion(), '\n');
@@ -261,6 +276,9 @@ pep405:
 	wchar_t *pname = uwsgi_calloc(sizeof(wchar_t) * (strlen(program_name)+1));
 	mbstowcs(pname, program_name, strlen(program_name)+1);
 	Py_SetProgramName(pname);
+#ifdef UWSGI_PY312
+	PyImport_AppendInittab("uwsgi", init_uwsgi3);
+#endif
 #else
 	Py_SetProgramName(program_name);
 #endif
@@ -623,21 +641,6 @@ next:
 
 
 
-PyDoc_STRVAR(uwsgi_py_doc, "uWSGI api module.");
-
-#ifdef PYTHREE
-static PyModuleDef uwsgi_module3 = {
-	PyModuleDef_HEAD_INIT,
-	"uwsgi",
-	uwsgi_py_doc,
-	-1,
-	NULL,
-};
-PyObject *init_uwsgi3(void) {
-	return PyModule_Create(&uwsgi_module3);
-}
-#endif
-
 void init_uwsgi_embedded_module() {
 	PyObject *new_uwsgi_module, *zero;
 	int i;
@@ -658,7 +661,9 @@ void init_uwsgi_embedded_module() {
 
 
 #ifdef PYTHREE
+#ifndef UWSGI_PY312
 	PyImport_AppendInittab("uwsgi", init_uwsgi3);
+#endif
 	new_uwsgi_module = PyImport_AddModule("uwsgi");
 #else
 	new_uwsgi_module = Py_InitModule3("uwsgi", NULL, uwsgi_py_doc);
@@ -1161,7 +1166,10 @@ void uwsgi_python_init_apps() {
 
 	// prepare for stack suspend/resume
 	if (uwsgi.async > 1) {
-#ifdef UWSGI_PY311
+#ifdef UWSGI_PY312
+               up.current_c_recursion_remaining = uwsgi_malloc(sizeof(int)*uwsgi.async);
+               up.current_py_recursion_remaining = uwsgi_malloc(sizeof(int)*uwsgi.async);
+#elif defined UWSGI_PY311
 		up.current_recursion_remaining = uwsgi_malloc(sizeof(int)*uwsgi.async);
 #else
 		up.current_recursion_depth = uwsgi_malloc(sizeof(int)*uwsgi.async);
@@ -1324,7 +1332,12 @@ void uwsgi_python_pre_uwsgi_fork() {
 		// Acquire the gil and import lock before forking in order to avoid
 		// deadlocks in workers
 		UWSGI_GET_GIL
+#if defined UWSGI_PY312
+		PyInterpreterState *interp = PyInterpreterState_Get();
+		_PyImport_AcquireLock(interp);
+#else
 		_PyImport_AcquireLock();
+#endif
 	}
 }
 
@@ -1336,7 +1349,12 @@ void uwsgi_python_post_uwsgi_fork(int st
 	if (uwsgi.has_threads) {
 		if (step == 0) {
 			// Release locks within master process
+#if defined UWSGI_PY312
+			PyInterpreterState *interp = PyInterpreterState_Get();
+			_PyImport_ReleaseLock(interp);
+#else
 			_PyImport_ReleaseLock();
+#endif
 			UWSGI_RELEASE_GIL
 		}
 		else {
@@ -1592,7 +1610,11 @@ void uwsgi_python_suspend(struct wsgi_re
 	PyGILState_Release(pgst);
 
 	if (wsgi_req) {
-#ifdef UWSGI_PY311
+#ifdef UWSGI_PY312
+		up.current_c_recursion_remaining[wsgi_req->async_id] = tstate->c_recursion_remaining;
+		up.current_py_recursion_remaining[wsgi_req->async_id] = tstate->py_recursion_remaining;
+		up.current_frame[wsgi_req->async_id] = tstate->cframe;
+#elif defined UWSGI_PY311
 		up.current_recursion_remaining[wsgi_req->async_id] = tstate->recursion_remaining;
 		up.current_frame[wsgi_req->async_id] = tstate->cframe;
 #else
@@ -1601,7 +1623,11 @@ void uwsgi_python_suspend(struct wsgi_re
 #endif
 	}
 	else {
-#ifdef UWSGI_PY311
+#ifdef UWSGI_PY312
+		up.current_main_c_recursion_remaining = tstate->c_recursion_remaining;
+		up.current_main_py_recursion_remaining = tstate->py_recursion_remaining;
+		up.current_main_frame = tstate->cframe;
+#elif defined UWSGI_PY311
 		up.current_main_recursion_remaining = tstate->recursion_remaining;
 		up.current_main_frame = tstate->cframe;
 #else
@@ -1835,7 +1861,11 @@ void uwsgi_python_resume(struct wsgi_req
 	PyGILState_Release(pgst);
 
 	if (wsgi_req) {
-#ifdef UWSGI_PY311
+#ifdef UWSGI_PY312
+		tstate->c_recursion_remaining = up.current_c_recursion_remaining[wsgi_req->async_id];
+		tstate->py_recursion_remaining = up.current_py_recursion_remaining[wsgi_req->async_id];
+		tstate->cframe = up.current_frame[wsgi_req->async_id];
+#elif defined UWSGI_PY311
 		tstate->recursion_remaining = up.current_recursion_remaining[wsgi_req->async_id];
 		tstate->cframe = up.current_frame[wsgi_req->async_id];
 #else
@@ -1844,7 +1874,11 @@ void uwsgi_python_resume(struct wsgi_req
 #endif
 	}
 	else {
-#ifdef UWSGI_PY311
+#ifdef UWSGI_PY312
+		tstate->c_recursion_remaining = up.current_main_c_recursion_remaining;
+		tstate->py_recursion_remaining = up.current_main_py_recursion_remaining;
+		tstate->cframe = up.current_main_frame;
+#elif defined UWSGI_PY311
 		tstate->recursion_remaining = up.current_main_recursion_remaining;
 		tstate->cframe = up.current_main_frame;
 #else
