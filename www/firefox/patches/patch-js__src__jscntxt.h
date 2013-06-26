$NetBSD: patch-js__src__jscntxt.h,v 1.2 2013/06/26 11:32:12 ryoon Exp $

From bugzilla, bug 840242, attachment v1
Use the runtime page size to control arena decommit.

As a side effect, this removes the hard coded page-size == 4k requirement.


diff js/src/jscntxt.h js/src/jscntxt.h
--- js/src/jscntxt.h.orig	2013-06-17 22:13:11.000000000 +0000
+++ js/src/jscntxt.h
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
 
