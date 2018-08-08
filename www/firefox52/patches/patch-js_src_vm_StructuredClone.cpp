$NetBSD: patch-js_src_vm_StructuredClone.cpp,v 1.1 2018/08/08 08:49:58 martin Exp $

Fix a crash on big endian machines. Reported in bugzilla
as #1481740.

--- js/src/vm/StructuredClone.cpp.orig	2018-06-21 20:53:54.000000000 +0200
+++ js/src/vm/StructuredClone.cpp	2018-08-08 10:15:04.949370197 +0200
@@ -925,6 +925,7 @@ JSStructuredCloneData::discardTransferab
 
         void* content;
         SCInput::getPtr(point.peek(), &content);
+	content = (void*)NativeEndian::swapFromLittleEndian(reinterpret_cast<uint64_t>(content));
         point.next();
         if (!point.canPeek())
             return;
