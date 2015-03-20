$NetBSD: patch-js_src_jit_none_Lowering-none.h,v 1.1 2015/03/20 10:13:57 martin Exp $

Fix for https://bugzilla.mozilla.org/show_bug.cgi?id=1145014

--- js/src/jit/none/Lowering-none.h.orig	2015-03-05 11:28:17.000000000 +0100
+++ js/src/jit/none/Lowering-none.h	2015-03-20 10:21:36.000000000 +0100
@@ -83,6 +83,7 @@
     bool visitCompareExchangeTypedArrayElement(MCompareExchangeTypedArrayElement *ins) { MOZ_CRASH(); }
     bool visitAsmJSCompareExchangeHeap(MAsmJSCompareExchangeHeap *ins) { MOZ_CRASH(); }
     bool visitAsmJSAtomicBinopHeap(MAsmJSAtomicBinopHeap *ins) { MOZ_CRASH(); }
+    bool visitSubstr(MSubstr *ins) { MOZ_CRASH(); }
 
     LTableSwitch *newLTableSwitch(LAllocation, LDefinition, MTableSwitch *) { MOZ_CRASH(); }
     LTableSwitchV *newLTableSwitchV(MTableSwitch *) { MOZ_CRASH(); }
