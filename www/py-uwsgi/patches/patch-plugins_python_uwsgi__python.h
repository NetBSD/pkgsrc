$NetBSD: patch-plugins_python_uwsgi__python.h,v 1.1 2023/10/29 18:18:03 wiz Exp $

Python 3.12 support
https://github.com/unbit/uwsgi/pull/2542

--- plugins/python/uwsgi_python.h.orig	2023-07-27 15:34:12.000000000 +0000
+++ plugins/python/uwsgi_python.h
@@ -21,6 +21,10 @@
 #  define UWSGI_PY311
 #endif
 
+#if (PY_VERSION_HEX >= 0x030c0000)
+#  define UWSGI_PY312
+#endif
+
 #if PY_MAJOR_VERSION == 2 && PY_MINOR_VERSION < 7
 #define HAS_NOT_PyMemoryView_FromBuffer
 #endif
@@ -168,7 +172,15 @@ struct uwsgi_python {
 
 	char *callable;
 
-#ifdef UWSGI_PY311
+#ifdef UWSGI_PY312
+	int *current_c_recursion_remaining;
+	int *current_py_recursion_remaining;
+	_PyCFrame **current_frame;
+
+	int current_main_c_recursion_remaining;
+	int current_main_py_recursion_remaining;
+	_PyCFrame *current_main_frame;
+#elif defined UWSGI_PY311
 	int *current_recursion_remaining;
 	_PyCFrame **current_frame;
 
