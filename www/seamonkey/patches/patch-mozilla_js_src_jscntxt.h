$NetBSD: patch-mozilla_js_src_jscntxt.h,v 1.1 2013/07/12 12:24:10 ryoon Exp $

--- mozilla/js/src/jscntxt.h.orig	2013-06-20 04:35:08.000000000 +0000
+++ mozilla/js/src/jscntxt.h
@@ -1101,6 +1101,15 @@ struct JSRuntime : js::RuntimeFriendFiel
     /* Stack of thread-stack-allocated GC roots. */
     js::AutoGCRooter   *autoGCRooters;
 
+    /*
+     * The GC can only safely decommit memory when the page size of the
+     * running process matches the compiled arena size.
+     */
+    size_t              gcSystemPageSize;
+
+    /* The OS allocation granularity may not match the page size. */
+    size_t              gcSystemAllocGranularity;
+
     /* Strong references on scripts held for PCCount profiling API. */
     js::ScriptAndCountsVector *scriptAndCountsVector;
 
