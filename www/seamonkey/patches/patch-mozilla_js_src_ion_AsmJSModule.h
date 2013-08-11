$NetBSD: patch-mozilla_js_src_ion_AsmJSModule.h,v 1.1 2013/08/11 03:18:46 ryoon Exp $

--- mozilla/js/src/ion/AsmJSModule.h.orig	2013-08-04 03:05:31.000000000 +0000
+++ mozilla/js/src/ion/AsmJSModule.h
@@ -582,12 +582,12 @@ class AsmJSModule
     }
 
     void setFunctionBytes(size_t functionBytes) {
-        JS_ASSERT(functionBytes % gc::PageSize == 0);
+        JS_ASSERT(functionBytes % AsmJSPageSize == 0);
         functionBytes_ = functionBytes;
     }
     size_t functionBytes() const {
         JS_ASSERT(functionBytes_);
-        JS_ASSERT(functionBytes_ % gc::PageSize == 0);
+        JS_ASSERT(functionBytes_ % AsmJSPageSize == 0);
         return functionBytes_;
     }
     bool containsPC(void *pc) const {
@@ -648,7 +648,7 @@ class AsmJSModule
 
 
     void takeOwnership(JSC::ExecutablePool *pool, uint8_t *code, size_t codeBytes, size_t totalBytes) {
-        JS_ASSERT(uintptr_t(code) % gc::PageSize == 0);
+        JS_ASSERT(uintptr_t(code) % AsmJSPageSize == 0);
         codePool_ = pool;
         code_ = code;
         codeBytes_ = codeBytes;
@@ -656,7 +656,7 @@ class AsmJSModule
     }
     uint8_t *functionCode() const {
         JS_ASSERT(code_);
-        JS_ASSERT(uintptr_t(code_) % gc::PageSize == 0);
+        JS_ASSERT(uintptr_t(code_) % AsmJSPageSize == 0);
         return code_;
     }
 
