$NetBSD: patch-mozilla_js_src_jstypedarray.cpp,v 1.1 2013/07/12 12:24:10 ryoon Exp $

--- mozilla/js/src/jstypedarray.cpp.orig	2013-06-20 04:35:08.000000000 +0000
+++ mozilla/js/src/jstypedarray.cpp
@@ -341,9 +341,9 @@ ArrayBufferObject::uninlineData(JSContex
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
@@ -364,17 +364,19 @@ ArrayBufferObject::prepareForAsmJS(JSCon
 # endif
 
     // Enable access to the valid region.
-    JS_ASSERT(buffer->byteLength() % AsmJSAllocationGranularity == 0);
+    JS_ASSERT(buffer->byteLength() % static const size_t AsmJSMappedSize = PageSize + AsmJSBufferProtectedSize;smJSAllocationGranularity == 0);
 # ifdef XP_WIN
-    if (!VirtualAlloc(p, PageSize + buffer->byteLength(), MEM_COMMIT, PAGE_READWRITE))
+    if (!VirtualAlloc(p, AsmJSPageSize + buffer->byteLength(), MEM_COMMIT, PAGE_READWRITE)) {
         return false;
+    }
 # else
-    if (mprotect(p, PageSize + buffer->byteLength(), PROT_READ | PROT_WRITE))
+    if (mprotect(p, AsmJSPageSize + buffer->byteLength(), PROT_READ | PROT_WRITE)) {
         return false;
+    }
 # endif
 
     // Copy over the current contents of the typed array.
-    uint8_t *data = reinterpret_cast<uint8_t*>(p) + PageSize;
+    uint8_t *data = reinterpret_cast<uint8_t*>(p) + AsmJSPageSize;
     memcpy(data, buffer->dataPointer(), buffer->byteLength());
 
     // Swap the new elements into the ArrayBufferObject.
@@ -396,8 +398,8 @@ ArrayBufferObject::releaseAsmJSArrayBuff
     ArrayBufferObject &buffer = obj->asArrayBuffer();
     JS_ASSERT(buffer.isAsmJSArrayBuffer());
 
-    uint8_t *p = buffer.dataPointer() - PageSize ;
-    JS_ASSERT(uintptr_t(p) % PageSize == 0);
+    uint8_t *p = buffer.dataPointer() - AsmJSPageSize ;
+    JS_ASSERT(uintptr_t(p) % AsmJSPageSize == 0);
 # ifdef XP_WIN
     VirtualFree(p, 0, MEM_RELEASE);
 # else
