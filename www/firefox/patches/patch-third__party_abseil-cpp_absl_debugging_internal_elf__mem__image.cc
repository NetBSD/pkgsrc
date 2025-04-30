$NetBSD: patch-third__party_abseil-cpp_absl_debugging_internal_elf__mem__image.cc,v 1.1 2025/04/30 03:10:40 ryoon Exp $

* NetBSD has no DT_GNU_HASH definition.

--- third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.cc.orig	2025-03-05 13:29:06.318414617 +0000
+++ third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.cc
@@ -221,6 +221,10 @@ void ElfMemImage::Init(const void *base)
   for (; dynamic_entry->d_tag != DT_NULL; ++dynamic_entry) {
     const auto value =
         static_cast<intptr_t>(dynamic_entry->d_un.d_val) + relocation;
+/* For NetBSD 9 */
+#if !defined(DT_GNU_HASH)
+#define DT_GNU_HASH 0x6ffffef5
+#endif
     switch (dynamic_entry->d_tag) {
       case DT_HASH:
         sysv_hash = reinterpret_cast<uint32_t *>(value);
