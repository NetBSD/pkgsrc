$NetBSD: patch-js_src_vm_ObjectImpl-inl.h,v 1.3 2013/08/07 12:17:54 ryoon Exp $

--- js/src/vm/ObjectImpl-inl.h.orig	2013-07-30 00:58:25.000000000 +0000
+++ js/src/vm/ObjectImpl-inl.h
@@ -217,9 +217,9 @@ js::ObjectImpl::initializeSlotRange(uint
     JSRuntime *rt = runtime();
     uint32_t offset = start;
     for (HeapSlot *sp = fixedStart; sp < fixedEnd; sp++)
-        sp->init(rt, this->asObjectPtr(), HeapSlot::Slot, offset++, UndefinedValue());
+        sp->init(rt, this->asObjectPtr(), HeapSlot::Slot, offset++, js::UndefinedValue());
     for (HeapSlot *sp = slotsStart; sp < slotsEnd; sp++)
-        sp->init(rt, this->asObjectPtr(), HeapSlot::Slot, offset++, UndefinedValue());
+        sp->init(rt, this->asObjectPtr(), HeapSlot::Slot, offset++, js::UndefinedValue());
 }
 
 inline bool
@@ -389,7 +389,7 @@ ZoneOfValue(const JS::Value &value)
 js::ObjectImpl::readBarrier(ObjectImpl *obj)
 {
 #ifdef JSGC_INCREMENTAL
-    Zone *zone = obj->zone();
+    JS::Zone *zone = obj->zone();
     if (zone->needsBarrier()) {
         MOZ_ASSERT(!zone->rt->isHeapBusy());
         JSObject *tmp = obj->asObjectPtr();
@@ -403,7 +403,7 @@ inline void
 js::ObjectImpl::privateWriteBarrierPre(void **old)
 {
 #ifdef JSGC_INCREMENTAL
-    Zone *zone = this->zone();
+    JS::Zone *zone = this->zone();
     if (zone->needsBarrier()) {
         if (*old && getClass()->trace)
             getClass()->trace(zone->barrierTracer(), this->asObjectPtr());
@@ -430,7 +430,7 @@ js::ObjectImpl::writeBarrierPre(ObjectIm
     if (IsNullTaggedPointer(obj) || !obj->runtime()->needsBarrier())
         return;
 
-    Zone *zone = obj->zone();
+    JS::Zone *zone = obj->zone();
     if (zone->needsBarrier()) {
         MOZ_ASSERT(!zone->rt->isHeapBusy());
         JSObject *tmp = obj->asObjectPtr();
