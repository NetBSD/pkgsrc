$NetBSD: patch-src_js_quickjs.h,v 1.1 2025/11/13 23:18:47 leot Exp $

JS_VALUE_GET_STRING is no longer exposed in quickjs-20250913,
define it.

--- src/js/quickjs.h.orig	2025-11-13 23:13:29.293860974 +0000
+++ src/js/quickjs.h
@@ -10,6 +10,10 @@ inline int operator<(JSValueConst a, JSV
 }
 #endif
 
+#if !defined(JS_VALUE_GET_STRING)
+#define JS_VALUE_GET_STRING(v) ((JSString *)JS_VALUE_GET_PTR(v))
+#endif
+
 #ifdef __cplusplus
 extern "C" {
 #endif
