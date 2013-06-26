$NetBSD: patch-js__src__gc__Marking.cpp,v 1.2 2013/06/26 11:32:12 ryoon Exp $

# HG changeset patch
# User Martin Husemann <martin@netbsd.org>
# Date 1370038993 -7200
# Node ID d16914942a9c502dde37dce2a1deb09050218ba8
# Parent  d296fcc8f3dd6254c862cdfd47a5580ee05a94f4
Bug 871101:  Make "kind" a full uintptr_t value so it overwrites its pointer union counterpart for sure r=billm

diff js/src/gc/Marking.cpp js/src/gc/Marking.cpp
--- js/src/gc/Marking.cpp.orig	2013-06-17 22:13:09.000000000 +0000
+++ js/src/gc/Marking.cpp
@@ -1143,7 +1143,7 @@ struct SlotArrayLayout
 {
     union {
         HeapSlot *end;
-        HeapSlot::Kind kind;
+        uintptr_t kind;
     };
     union {
         HeapSlot *start;
