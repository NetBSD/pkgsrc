$NetBSD: patch-mozilla_js_src_jscompartment.h,v 1.1 2013/05/23 13:25:30 ryoon Exp $

--- mozilla/js/src/jscompartment.h.orig	2013-05-03 03:07:59.000000000 +0000
+++ mozilla/js/src/jscompartment.h
@@ -596,12 +596,12 @@ class js::AutoDebugModeGC
         // The DEBUG_MODE_GC reason forces the collector to always throw
         // everything away, as required for debug mode transitions.
         if (needGC)
-            GC(rt, GC_NORMAL, gcreason::DEBUG_MODE_GC);
+            GC(rt, GC_NORMAL, js::gcreason::DEBUG_MODE_GC);
     }
 
-    void scheduleGC(Zone *zone) {
+    void scheduleGC(JS::Zone *zone) {
         JS_ASSERT(!rt->isHeapBusy());
-        PrepareZoneForGC(zone);
+        js::PrepareZoneForGC(zone);
         needGC = true;
     }
 };
