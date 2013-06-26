$NetBSD: patch-js_src_jscompartment.h,v 1.2 2013/06/26 11:32:12 ryoon Exp $

--- js/src/jscompartment.h.orig	2013-06-17 22:13:11.000000000 +0000
+++ js/src/jscompartment.h
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
