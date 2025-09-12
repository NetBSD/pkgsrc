$NetBSD: patch-base_debug_elf__reader.cc,v 1.7 2025/09/12 16:02:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/debug/elf_reader.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ base/debug/elf_reader.cc
@@ -49,6 +49,10 @@ using Xword = Elf64_Xword;
 
 constexpr char kGnuNoteName[] = "GNU";
 
+#ifndef NT_GNU_BUILD_ID
+#define NT_GNU_BUILD_ID 3
+#endif
+
 // Returns a pointer to the header of the ELF binary mapped into memory, or a
 // null pointer if the header is invalid. Here and below |elf_mapped_base| is a
 // pointer to the start of the ELF image.
