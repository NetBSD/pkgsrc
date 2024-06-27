$NetBSD: patch-src_nxt__script.c,v 1.2 2024/06/27 16:03:25 osa Exp $

Fix build with the recent versions of NGINX JavaScript

--- src/nxt_script.c.orig	2024-03-21 13:47:41.000000000 +0000
+++ src/nxt_script.c
@@ -37,14 +37,6 @@ static void nxt_script_buf_completion(nx
 static nxt_lvlhsh_t  nxt_script_info;
 
 
-static njs_vm_ops_t  nxt_js_ops = {
-    NULL,
-    NULL,
-    nxt_js_module_loader,
-    NULL,
-};
-
-
 nxt_script_t *
 nxt_script_new(nxt_task_t *task, nxt_str_t *name, u_char *data, size_t size,
     u_char *error)
@@ -63,8 +55,6 @@ nxt_script_new(nxt_task_t *task, nxt_str
     opts.file.start = (u_char *) "default";
     opts.file.length = 7;
 
-    opts.ops = &nxt_js_ops;
-
     vm = njs_vm_create(&opts);
     if (nxt_slow_path(vm == NULL)) {
         return NULL;
