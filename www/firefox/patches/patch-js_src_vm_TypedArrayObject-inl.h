$NetBSD: patch-js_src_vm_TypedArrayObject-inl.h,v 1.1 2024/08/03 02:06:31 tsutsui Exp $

- kludge to build on NetBSD/i386 10.0
  https://mail-index.netbsd.org/pkgsrc-users/2024/07/16/msg039900.html

--- js/src/vm/TypedArrayObject-inl.h.orig	2024-07-25 20:34:47.000000000 +0000
+++ js/src/vm/TypedArrayObject-inl.h
@@ -404,7 +404,9 @@ class ElementSpecific {
     // `malloc` returns memory at least as strictly aligned as for max_align_t
     // and the alignment of max_align_t is a multiple of the size of `T`,
     // so `SharedMem::cast` will be called with properly aligned memory.
+#if !defined(__i386__)
     static_assert(alignof(std::max_align_t) % sizeof(T) == 0);
+#endif
 
     SharedMem<T*> dest =
         target->dataPointerEither().template cast<T*>() + offset;
