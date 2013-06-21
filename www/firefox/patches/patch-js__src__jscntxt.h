$NetBSD: patch-js__src__jscntxt.h,v 1.1 2013/06/21 23:11:42 ryoon Exp $

From bugzilla, bug 840242, attachment v1
Use the runtime page size to control arena decommit.

As a side effect, this removes the hard coded page-size == 4k requirement.


diff js/src/jscntxt.h js/src/jscntxt.h
--- js/src/jscntxt.h
+++ js/src/jscntxt.h
@@ -1132,16 +1132,25 @@ struct JSRuntime : public JS::shadow::Ru
     JSTraceDataOp       gcBlackRootsTraceOp;
     void                *gcBlackRootsData;
     JSTraceDataOp       gcGrayRootsTraceOp;
     void                *gcGrayRootsData;
 
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
 
     /* Well-known numbers held for use by this runtime's contexts. */
     js::Value           NaNValue;
     js::Value           negativeInfinityValue;
     js::Value           positiveInfinityValue;
 
