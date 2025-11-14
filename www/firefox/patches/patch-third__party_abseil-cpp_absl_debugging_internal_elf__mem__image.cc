$NetBSD: patch-third__party_abseil-cpp_absl_debugging_internal_elf__mem__image.cc,v 1.2 2025/11/14 17:17:18 ryoon Exp $

* NetBSD has no DT_GNU_HASH definition.

--- third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.cc.orig	2025-11-06 22:07:37.000000000 +0000
+++ third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.cc
@@ -25,6 +25,10 @@
 #include <cstddef>
 #include <cstdint>
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
+
 #include "absl/base/config.h"
 #include "absl/base/internal/raw_logging.h"
 
@@ -221,6 +225,10 @@ void ElfMemImage::Init(const void *base)
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
@@ -377,7 +385,7 @@ void ElfMemImage::SymbolIterator::Update
   const ElfW(Versym) *version_symbol = image->GetVersym(index_);
   ABSL_RAW_CHECK(symbol && version_symbol, "");
   const char *const symbol_name = image->GetDynstr(symbol->st_name);
-#if defined(__NetBSD__)
+#if defined(__NetBSD__) && __NetBSD_Version__ < 1199000400
   const int version_index = version_symbol->vs_vers & VERSYM_VERSION;
 #else
   const ElfW(Versym) version_index = version_symbol[0] & VERSYM_VERSION;
