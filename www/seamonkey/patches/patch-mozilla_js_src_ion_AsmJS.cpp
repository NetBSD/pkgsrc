$NetBSD: patch-mozilla_js_src_ion_AsmJS.cpp,v 1.1 2013/07/12 12:24:10 ryoon Exp $

--- mozilla/js/src/ion/AsmJS.cpp.orig	2013-06-20 04:35:07.000000000 +0000
+++ mozilla/js/src/ion/AsmJS.cpp
@@ -1324,7 +1324,7 @@ class ModuleCompiler
 
     void setSecondPassComplete() {
         JS_ASSERT(currentPass_ == 2);
-        masm_.align(gc::PageSize);
+        masm_.align(AsmJSPageSize);
         module_->setFunctionBytes(masm_.size());
         currentPass_ = 3;
     }
@@ -1357,7 +1357,7 @@ class ModuleCompiler
 
         // The code must be page aligned, so include extra space so that we can
         // AlignBytes the allocation result below.
-        size_t allocedBytes = totalBytes + gc::PageSize;
+        size_t allocedBytes = totalBytes + AsmJSPageSize;
 
         // Allocate the slab of memory.
         JSC::ExecutableAllocator *execAlloc = cx_->compartment->ionCompartment()->execAlloc();
@@ -1365,7 +1365,7 @@ class ModuleCompiler
         uint8_t *unalignedBytes = (uint8_t*)execAlloc->alloc(allocedBytes, &pool, JSC::ASMJS_CODE);
         if (!unalignedBytes)
             return false;
-        uint8_t *code = (uint8_t*)AlignBytes((uintptr_t)unalignedBytes, gc::PageSize);
+        uint8_t *code = (uint8_t*)AlignBytes((uintptr_t)unalignedBytes, AsmJSPageSize);
 
         // The ExecutablePool owns the memory and must be released by the AsmJSModule.
         module_->takeOwnership(pool, code, codeBytes, totalBytes);
