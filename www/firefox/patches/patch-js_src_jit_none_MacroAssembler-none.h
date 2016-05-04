$NetBSD: patch-js_src_jit_none_MacroAssembler-none.h,v 1.1 2016/05/04 16:22:35 martin Exp $

See https://bugzilla.mozilla.org/show_bug.cgi?id=1266366

--- js/src/jit/none/MacroAssembler-none.h.orig	2016-04-22 02:37:27.000000000 +0200
+++ js/src/jit/none/MacroAssembler-none.h	2016-05-04 18:04:09.836344041 +0200
@@ -255,6 +255,8 @@ class MacroAssemblerNone : public Assemb
     template <typename T, typename S> void branchPrivatePtr(Condition, T, S, Label*) { MOZ_CRASH(); }
     template <typename T, typename S> void decBranchPtr(Condition, T, S, Label*) { MOZ_CRASH(); }
     template <typename T, typename S> void branchTest64(Condition, T, T, S, Label*) { MOZ_CRASH(); }
+    template <typename T, typename S> void branch64(Condition, T, S, Label*) { MOZ_CRASH(); }
+    template <typename T, typename S> void branch64(Condition, T, T, S, Label*) { MOZ_CRASH(); }
     template <typename T, typename S> void mov(T, S) { MOZ_CRASH(); }
     template <typename T, typename S> void movq(T, S) { MOZ_CRASH(); }
     template <typename T, typename S> void movePtr(T, S) { MOZ_CRASH(); }
