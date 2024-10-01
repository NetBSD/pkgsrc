$NetBSD: patch-js_src_vm_TypedArrayObject-inl.h,v 1.2 2024/10/01 12:47:19 ryoon Exp $

- kludge to build on NetBSD/i386 10.0
  https://mail-index.netbsd.org/pkgsrc-users/2024/07/16/msg039900.html

--- js/src/vm/TypedArrayObject-inl.h.orig	2024-08-23 12:51:13.000000000 +0000
+++ js/src/vm/TypedArrayObject-inl.h
@@ -435,7 +435,9 @@ class ElementSpecific {
     // `malloc` returns memory at least as strictly aligned as for max_align_t
     // and the alignment of max_align_t is a multiple of the size of `T`,
     // so `SharedMem::cast` will be called with properly aligned memory.
+#if !defined(__i386__)
     static_assert(alignof(std::max_align_t) % sizeof(T) == 0);
+#endif
 
     SharedMem<T*> dest = Ops::extract(target).template cast<T*>() + offset;
     SharedMem<void*> data = Ops::extract(source);
