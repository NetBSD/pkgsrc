$NetBSD: patch-src_3rdparty_chromium_base_debug_elf__reader.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/debug/elf_reader.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/debug/elf_reader.cc
@@ -38,7 +38,9 @@ using Nhdr = Elf64_Nhdr;
 using Word = Elf64_Word;
 #endif
 
+#if !defined(OS_BSD)
 constexpr char kGnuNoteName[] = "GNU";
+#endif
 
 // Returns a pointer to the header of the ELF binary mapped into memory, or a
 // null pointer if the header is invalid. Here and below |elf_mapped_base| is a
@@ -75,6 +77,7 @@ size_t ReadElfBuildId(const void* elf_ma
     bool found = false;
     while (current_section < section_end) {
       current_note = reinterpret_cast<const Nhdr*>(current_section);
+#if !defined(OS_BSD)
       if (current_note->n_type == NT_GNU_BUILD_ID) {
         StringPiece note_name(current_section + sizeof(Nhdr),
                               current_note->n_namesz);
@@ -84,6 +87,7 @@ size_t ReadElfBuildId(const void* elf_ma
           break;
         }
       }
+#endif
 
       size_t section_size = bits::Align(current_note->n_namesz, 4) +
                             bits::Align(current_note->n_descsz, 4) +
