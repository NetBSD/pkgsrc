$NetBSD: patch-src_python_nxt__python.c,v 1.1 2022/12/06 08:54:23 wiz Exp $

Python 3.11 support.
https://github.com/nginx/unit/commit/491d0f700f5690eba0f1fcf2124f3a37ef73eb1a

--- src/python/nxt_python.c.orig	2022-09-12 23:26:26.000000000 +0000
+++ src/python/nxt_python.c
@@ -22,6 +22,10 @@ typedef struct {
 } nxt_py_thread_info_t;
 
 
+#if PY_MAJOR_VERSION == 3
+static nxt_int_t nxt_python3_init_config(nxt_int_t pep405);
+#endif
+
 static nxt_int_t nxt_python_start(nxt_task_t *task,
     nxt_process_data_t *data);
 static nxt_int_t nxt_python_set_target(nxt_task_t *task,
@@ -64,6 +68,63 @@ static nxt_py_thread_info_t  *nxt_py_thr
 static nxt_python_proto_t    nxt_py_proto;
 
 
+#if PY_VERSION_HEX >= NXT_PYTHON_VER(3, 8)
+
+static nxt_int_t
+nxt_python3_init_config(nxt_int_t pep405)
+{
+    PyStatus  status;
+    PyConfig  config;
+
+    PyConfig_InitIsolatedConfig(&config);
+
+    if (pep405) {
+        status = PyConfig_SetString(&config, &config.program_name,
+                                    nxt_py_home);
+        if (PyStatus_Exception(status)) {
+            goto pyinit_exception;
+        }
+
+    } else {
+        status =PyConfig_SetString(&config, &config.home, nxt_py_home);
+        if (PyStatus_Exception(status)) {
+            goto pyinit_exception;
+        }
+    }
+
+    status = Py_InitializeFromConfig(&config);
+    if (PyStatus_Exception(status)) {
+        goto pyinit_exception;
+    }
+    PyConfig_Clear(&config);
+
+    return NXT_OK;
+
+pyinit_exception:
+
+    PyConfig_Clear(&config);
+
+    return NXT_ERROR;
+}
+
+#elif PY_MAJOR_VERSION == 3
+
+static nxt_int_t
+nxt_python3_init_config(nxt_int_t pep405)
+{
+    if (pep405) {
+        Py_SetProgramName(nxt_py_home);
+
+    } else {
+        Py_SetPythonHome(nxt_py_home);
+    }
+
+    return NXT_OK;
+}
+
+#endif
+
+
 static nxt_int_t
 nxt_python_start(nxt_task_t *task, nxt_process_data_t *data)
 {
@@ -127,11 +188,15 @@ nxt_python_start(nxt_task_t *task, nxt_p
         if (pep405) {
             mbstowcs(nxt_py_home, c->home, len);
             mbstowcs(nxt_py_home + len, bin_python, sizeof(bin_python));
-            Py_SetProgramName(nxt_py_home);
 
         } else {
             mbstowcs(nxt_py_home, c->home, len + 1);
-            Py_SetPythonHome(nxt_py_home);
+        }
+
+        ret = nxt_python3_init_config(pep405);
+        if (nxt_slow_path(ret == NXT_ERROR)) {
+            nxt_alert(task, "Failed to initialise config");
+            return NXT_ERROR;
         }
 
 #else
