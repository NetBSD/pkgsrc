$NetBSD: patch-base_debug_elf__reader.cc,v 1.14 2026/01/19 16:14:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/debug/elf_reader.cc.orig	2026-01-07 00:50:30.000000000 +0000
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
