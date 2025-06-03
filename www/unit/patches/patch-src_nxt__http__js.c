$NetBSD: patch-src_nxt__http__js.c,v 1.3 2025/06/03 22:59:20 osa Exp $

Adopt njs-0.9.0

--- src/nxt_http_js.c.orig	2025-02-27 22:02:21.000000000 +0000
+++ src/nxt_http_js.c
@@ -9,27 +9,31 @@
 
 
 static njs_int_t nxt_http_js_ext_uri(njs_vm_t *vm, njs_object_prop_t *prop,
-    njs_value_t *value, njs_value_t *setval, njs_value_t *retval);
+    uint32_t atom_id, njs_value_t *value, njs_value_t *setval,
+    njs_value_t *retval);
 static njs_int_t nxt_http_js_ext_host(njs_vm_t *vm, njs_object_prop_t *prop,
-    njs_value_t *value, njs_value_t *setval, njs_value_t *retval);
-static njs_int_t nxt_http_js_ext_remote_addr(njs_vm_t *vm,
-    njs_object_prop_t *prop, njs_value_t *value, njs_value_t *setval,
+    uint32_t atom_id, njs_value_t *value, njs_value_t *setval,
     njs_value_t *retval);
+static njs_int_t nxt_http_js_ext_remote_addr(njs_vm_t *vm,
+    njs_object_prop_t *prop, uint32_t atom_id, njs_value_t *value,
+    njs_value_t *setval, njs_value_t *retval);
 static njs_int_t nxt_http_js_ext_get_args(njs_vm_t *vm,
-    njs_object_prop_t *prop, njs_value_t *value, njs_value_t *setval,
-    njs_value_t *retval);
+    njs_object_prop_t *prop, uint32_t atom_id, njs_value_t *value,
+    njs_value_t *setval, njs_value_t *retval);
 static njs_int_t nxt_http_js_ext_get_header(njs_vm_t *vm,
-    njs_object_prop_t *prop, njs_value_t *value, njs_value_t *setval,
-    njs_value_t *retval);
+    njs_object_prop_t *prop, uint32_t atom_id, njs_value_t *value,
+    njs_value_t *setval, njs_value_t *retval);
 static njs_int_t nxt_http_js_ext_keys_header(njs_vm_t *vm,
     njs_value_t *value, njs_value_t *keys);
 static njs_int_t nxt_http_js_ext_get_cookie(njs_vm_t *vm,
-    njs_object_prop_t *prop, njs_value_t *value, njs_value_t *setval,
+    njs_object_prop_t *prop, uint32_t atom_id, njs_value_t *value,
+    njs_value_t *setval,
     njs_value_t *retval);
 static njs_int_t nxt_http_js_ext_keys_cookie(njs_vm_t *vm, njs_value_t *value,
     njs_value_t *keys);
 static njs_int_t nxt_http_js_ext_get_var(njs_vm_t *vm, njs_object_prop_t *prop,
-    njs_value_t *value, njs_value_t *setval, njs_value_t *retval);
+    uint32_t atom_id, njs_value_t *value, njs_value_t *setval,
+    njs_value_t *retval);
 
 
 static njs_external_t  nxt_http_js_proto[] = {
@@ -109,7 +113,7 @@ nxt_http_register_js_proto(nxt_js_conf_t
 
 
 static njs_int_t
-nxt_http_js_ext_uri(njs_vm_t *vm, njs_object_prop_t *prop,
+nxt_http_js_ext_uri(njs_vm_t *vm, njs_object_prop_t *prop, uint32_t atom_id,
     njs_value_t *value, njs_value_t *setval, njs_value_t *retval)
 {
     nxt_http_request_t  *r;
@@ -126,7 +130,7 @@ nxt_http_js_ext_uri(njs_vm_t *vm, njs_ob
 
 
 static njs_int_t
-nxt_http_js_ext_host(njs_vm_t *vm, njs_object_prop_t *prop,
+nxt_http_js_ext_host(njs_vm_t *vm, njs_object_prop_t *prop, uint32_t atom_id,
     njs_value_t *value, njs_value_t *setval, njs_value_t *retval)
 {
     nxt_http_request_t  *r;
@@ -144,7 +148,8 @@ nxt_http_js_ext_host(njs_vm_t *vm, njs_o
 
 static njs_int_t
 nxt_http_js_ext_remote_addr(njs_vm_t *vm, njs_object_prop_t *prop,
-    njs_value_t *value, njs_value_t *setval, njs_value_t *retval)
+    uint32_t atom_id, njs_value_t *value, njs_value_t *setval,
+    njs_value_t *retval)
 {
     nxt_http_request_t  *r;
 
@@ -162,7 +167,8 @@ nxt_http_js_ext_remote_addr(njs_vm_t *vm
 
 static njs_int_t
 nxt_http_js_ext_get_args(njs_vm_t *vm, njs_object_prop_t *prop,
-    njs_value_t *value, njs_value_t *setval, njs_value_t *retval)
+    uint32_t atom_id, njs_value_t *value, njs_value_t *setval,
+    njs_value_t *retval)
 {
     u_char              *start;
     njs_int_t           ret;
@@ -193,7 +199,8 @@ nxt_http_js_ext_get_args(njs_vm_t *vm, n
 
 static njs_int_t
 nxt_http_js_ext_get_header(njs_vm_t *vm, njs_object_prop_t *prop,
-    njs_value_t *value, njs_value_t *setval, njs_value_t *retval)
+    uint32_t atom_id, njs_value_t *value, njs_value_t *setval,
+    njs_value_t *retval)
 {
     njs_int_t           rc;
     njs_str_t           key;
@@ -206,7 +213,7 @@ nxt_http_js_ext_get_header(njs_vm_t *vm,
         return NJS_DECLINED;
     }
 
-    rc = njs_vm_prop_name(vm, prop, &key);
+    rc = njs_vm_prop_name(vm, atom_id, &key);
     if (rc != NJS_OK) {
         njs_value_undefined_set(retval);
         return NJS_DECLINED;
@@ -266,7 +273,8 @@ nxt_http_js_ext_keys_header(njs_vm_t *vm
 
 static njs_int_t
 nxt_http_js_ext_get_cookie(njs_vm_t *vm, njs_object_prop_t *prop,
-    njs_value_t *value, njs_value_t *setval, njs_value_t *retval)
+    uint32_t atom_id, njs_value_t *value, njs_value_t *setval,
+    njs_value_t *retval)
 {
     njs_int_t              rc;
     njs_str_t              key;
@@ -280,7 +288,7 @@ nxt_http_js_ext_get_cookie(njs_vm_t *vm,
         return NJS_DECLINED;
     }
 
-    rc = njs_vm_prop_name(vm, prop, &key);
+    rc = njs_vm_prop_name(vm, atom_id, &key);
     if (rc != NJS_OK) {
         njs_value_undefined_set(retval);
         return NJS_DECLINED;
@@ -355,7 +363,8 @@ nxt_http_js_ext_keys_cookie(njs_vm_t *vm
 
 static njs_int_t
 nxt_http_js_ext_get_var(njs_vm_t *vm, njs_object_prop_t *prop,
-    njs_value_t *value, njs_value_t *setval, njs_value_t *retval)
+    uint32_t atom_id, njs_value_t *value, njs_value_t *setval,
+    njs_value_t *retval)
 {
     njs_int_t           rc;
     njs_str_t           key;
@@ -369,7 +378,7 @@ nxt_http_js_ext_get_var(njs_vm_t *vm, nj
         return NJS_DECLINED;
     }
 
-    rc = njs_vm_prop_name(vm, prop, &key);
+    rc = njs_vm_prop_name(vm, atom_id, &key);
     if (rc != NJS_OK) {
         njs_value_undefined_set(retval);
         return NJS_DECLINED;
