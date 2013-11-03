$NetBSD: patch-js_src_vm_ObjectImpl-inl.h,v 1.1 2013/11/03 04:51:59 ryoon Exp $

--- js/src/vm/ObjectImpl-inl.h.orig	2013-09-10 03:43:39.000000000 +0000
+++ js/src/vm/ObjectImpl-inl.h
@@ -364,7 +364,7 @@ js::ObjectImpl::zone() const
 js::ObjectImpl::readBarrier(ObjectImpl *obj)
 {
 #ifdef JSGC_INCREMENTAL
-    Zone *zone = obj->zone();
+    JS::Zone *zone = obj->zone();
     if (zone->needsBarrier()) {
         MOZ_ASSERT(!zone->rt->isHeapMajorCollecting());
         JSObject *tmp = obj->asObjectPtr();
@@ -378,7 +378,7 @@ inline void
 js::ObjectImpl::privateWriteBarrierPre(void **old)
 {
 #ifdef JSGC_INCREMENTAL
-    Zone *zone = this->zone();
+    JS::Zone *zone = this->zone();
     if (zone->needsBarrier()) {
         if (*old && getClass()->trace)
             getClass()->trace(zone->barrierTracer(), this->asObjectPtr());
@@ -405,7 +405,7 @@ js::ObjectImpl::writeBarrierPre(ObjectIm
     if (IsNullTaggedPointer(obj) || !obj->runtime()->needsBarrier())
         return;
 
-    Zone *zone = obj->zone();
+    JS::Zone *zone = obj->zone();
     if (zone->needsBarrier()) {
         MOZ_ASSERT(!zone->rt->isHeapMajorCollecting());
         JSObject *tmp = obj->asObjectPtr();
