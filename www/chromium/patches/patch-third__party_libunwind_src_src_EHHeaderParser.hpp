$NetBSD: patch-third__party_libunwind_src_src_EHHeaderParser.hpp,v 1.3 2026/04/10 17:32:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/libunwind/src/src/EHHeaderParser.hpp.orig	2026-04-06 16:25:54.000000000 +0000
+++ third_party/libunwind/src/src/EHHeaderParser.hpp
@@ -161,6 +161,10 @@ bool EHHeaderParser<A>::findFDE(A &addre
 
 template <typename A>
 size_t EHHeaderParser<A>::getTableEntrySize(uint8_t tableEnc) {
+  if (tableEnc == DW_EH_PE_omit) {
+    return 0;
+  }
+
   switch (tableEnc & 0x0f) {
   case DW_EH_PE_sdata2:
   case DW_EH_PE_udata2:
@@ -174,8 +178,6 @@ size_t EHHeaderParser<A>::getTableEntryS
   case DW_EH_PE_sleb128:
   case DW_EH_PE_uleb128:
     _LIBUNWIND_ABORT("Can't binary search on variable length encoded data.");
-  case DW_EH_PE_omit:
-    return 0;
   default:
     _LIBUNWIND_ABORT("Unknown DWARF encoding for search table.");
   }
