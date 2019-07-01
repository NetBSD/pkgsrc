$NetBSD: patch-src_3rdparty_javascriptcore_JavaScriptCore_jit_JITStubs.h,v 1.1 2019/07/01 15:49:16 adam Exp $

Fix for LTO builds.

--- src/3rdparty/javascriptcore/JavaScriptCore/jit/JITStubs.h.orig	2019-07-01 15:35:48.000000000 +0000
+++ src/3rdparty/javascriptcore/JavaScriptCore/jit/JITStubs.h
@@ -316,7 +316,7 @@ extern "C" {
     EncodedJSValue JIT_STUB cti_op_to_primitive(STUB_ARGS_DECLARATION);
     EncodedJSValue JIT_STUB cti_op_typeof(STUB_ARGS_DECLARATION);
     EncodedJSValue JIT_STUB cti_op_urshift(STUB_ARGS_DECLARATION);
-    EncodedJSValue JIT_STUB cti_vm_throw(STUB_ARGS_DECLARATION);
+    EncodedJSValue JIT_STUB cti_vm_throw(STUB_ARGS_DECLARATION) __attribute__((used));
     EncodedJSValue JIT_STUB cti_to_object(STUB_ARGS_DECLARATION);
     JSObject* JIT_STUB cti_op_construct_JSConstruct(STUB_ARGS_DECLARATION);
     JSObject* JIT_STUB cti_op_new_array(STUB_ARGS_DECLARATION);
