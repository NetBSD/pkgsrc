$NetBSD: patch-mozilla_js_src_gc_Marking.cpp,v 1.1 2013/07/12 12:24:10 ryoon Exp $

--- mozilla/js/src/gc/Marking.cpp.orig	2013-06-20 04:35:07.000000000 +0000
+++ mozilla/js/src/gc/Marking.cpp
@@ -1143,7 +1143,7 @@ struct SlotArrayLayout
 {
     union {
         HeapSlot *end;
-        HeapSlot::Kind kind;
+        uintptr_t kind;
     };
     union {
         HeapSlot *start;
