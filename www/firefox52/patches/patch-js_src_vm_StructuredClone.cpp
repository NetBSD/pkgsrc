$NetBSD: patch-js_src_vm_StructuredClone.cpp,v 1.2 2022/06/03 16:30:00 martin Exp $

Fix a crash on big endian machines. Reported in bugzilla
as #1481740.

--- js/src/vm/StructuredClone.cpp.orig	2018-06-21 20:53:54.000000000 +0200
+++ js/src/vm/StructuredClone.cpp	2018-08-08 10:15:04.949370197 +0200
@@ -923,8 +923,7 @@ JSStructuredCloneData::discardTransferab
         if (!point.canPeek())
             return;
 
-        void* content;
-        SCInput::getPtr(point.peek(), &content);
+        void* content = (void*)NativeEndian::swapFromLittleEndian(point.peek());
         point.next();
         if (!point.canPeek())
             return;
