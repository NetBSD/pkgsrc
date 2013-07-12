$NetBSD: patch-mozilla_js_src_vm_ObjectImpl-inl.h,v 1.2 2013/07/12 12:24:10 ryoon Exp $

--- mozilla/js/src/vm/ObjectImpl-inl.h.orig	2013-06-20 04:35:09.000000000 +0000
+++ mozilla/js/src/vm/ObjectImpl-inl.h
@@ -181,9 +181,9 @@ js::ObjectImpl::initializeSlotRange(uint
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
@@ -353,7 +353,7 @@ ZoneOfValue(const JS::Value &value)
 js::ObjectImpl::readBarrier(ObjectImpl *obj)
 {
 #ifdef JSGC_INCREMENTAL
-    Zone *zone = obj->zone();
+    JS::Zone *zone = obj->zone();
     if (zone->needsBarrier()) {
         MOZ_ASSERT(!zone->rt->isHeapBusy());
         JSObject *tmp = obj->asObjectPtr();
@@ -367,7 +367,7 @@ inline void
 js::ObjectImpl::privateWriteBarrierPre(void **old)
 {
 #ifdef JSGC_INCREMENTAL
-    Zone *zone = this->zone();
+    JS::Zone *zone = this->zone();
     if (zone->needsBarrier()) {
         if (*old && getClass()->trace)
             getClass()->trace(zone->barrierTracer(), this->asObjectPtr());
@@ -394,7 +394,7 @@ js::ObjectImpl::writeBarrierPre(ObjectIm
     if (IsNullTaggedPointer(obj))
         return;
 
-    Zone *zone = obj->zone();
+    JS::Zone *zone = obj->zone();
     if (zone->needsBarrier()) {
         MOZ_ASSERT(!zone->rt->isHeapBusy());
         JSObject *tmp = obj->asObjectPtr();
