$NetBSD: patch-mozilla_js_src_jstypedarray.cpp,v 1.2 2013/08/11 03:18:46 ryoon Exp $

--- mozilla/js/src/jstypedarray.cpp.orig	2013-08-04 03:05:33.000000000 +0000
+++ mozilla/js/src/jstypedarray.cpp
@@ -338,9 +338,9 @@ ArrayBufferObject::uninlineData(JSContex
 //                            |            \                             /
 //                      obj->elements       required to be page boundaries
 //
-JS_STATIC_ASSERT(sizeof(ObjectElements) < PageSize);
-JS_STATIC_ASSERT(AsmJSAllocationGranularity == PageSize);
-static const size_t AsmJSMappedSize = PageSize + AsmJSBufferProtectedSize;
+JS_STATIC_ASSERT(sizeof(ObjectElements) < AsmJSPageSize);
+JS_STATIC_ASSERT(AsmJSAllocationGranularity == AsmJSPageSize);
+static const size_t AsmJSMappedSize = AsmJSPageSize + AsmJSBufferProtectedSize;
 
 bool
 ArrayBufferObject::prepareForAsmJS(JSContext *cx, Handle<ArrayBufferObject*> buffer)
@@ -363,19 +363,19 @@ ArrayBufferObject::prepareForAsmJS(JSCon
     // Enable access to the valid region.
     JS_ASSERT(buffer->byteLength() % AsmJSAllocationGranularity == 0);
 # ifdef XP_WIN
-    if (!VirtualAlloc(p, PageSize + buffer->byteLength(), MEM_COMMIT, PAGE_READWRITE)) {
+    if (!VirtualAlloc(p, AsmJSPageSize + buffer->byteLength(), MEM_COMMIT, PAGE_READWRITE)) {
         VirtualFree(p, 0, MEM_RELEASE);
         return false;
     }
 # else
-    if (mprotect(p, PageSize + buffer->byteLength(), PROT_READ | PROT_WRITE)) {
+    if (mprotect(p, AsmJSPageSize + buffer->byteLength(), PROT_READ | PROT_WRITE)) {
         munmap(p, AsmJSMappedSize);
         return false;
     }
 # endif
 
     // Copy over the current contents of the typed array.
-    uint8_t *data = reinterpret_cast<uint8_t*>(p) + PageSize;
+    uint8_t *data = reinterpret_cast<uint8_t*>(p) + AsmJSPageSize;
     memcpy(data, buffer->dataPointer(), buffer->byteLength());
 
     // Swap the new elements into the ArrayBufferObject.
@@ -397,8 +397,8 @@ ArrayBufferObject::releaseAsmJSArrayBuff
     ArrayBufferObject &buffer = obj->asArrayBuffer();
     JS_ASSERT(buffer.isAsmJSArrayBuffer());
 
-    uint8_t *p = buffer.dataPointer() - PageSize ;
-    JS_ASSERT(uintptr_t(p) % PageSize == 0);
+    uint8_t *p = buffer.dataPointer() - AsmJSPageSize ;
+    JS_ASSERT(uintptr_t(p) % AsmJSPageSize == 0);
 # ifdef XP_WIN
     VirtualFree(p, 0, MEM_RELEASE);
 # else
