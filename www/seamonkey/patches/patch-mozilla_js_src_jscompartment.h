$NetBSD: patch-mozilla_js_src_jscompartment.h,v 1.2 2013/07/12 12:24:10 ryoon Exp $

--- mozilla/js/src/jscompartment.h.orig	2013-06-20 04:35:08.000000000 +0000
+++ mozilla/js/src/jscompartment.h
@@ -396,9 +396,9 @@ class js::AutoDebugModeGC
             GC(rt, GC_NORMAL, JS::gcreason::DEBUG_MODE_GC);
     }
 
-    void scheduleGC(Zone *zone) {
+    void scheduleGC(JS::Zone *zone) {
         JS_ASSERT(!rt->isHeapBusy());
-        PrepareZoneForGC(zone);
+        JS::PrepareZoneForGC(zone);
         needGC = true;
     }
 };
