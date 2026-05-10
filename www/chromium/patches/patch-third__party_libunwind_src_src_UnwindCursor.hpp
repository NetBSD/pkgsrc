$NetBSD: patch-third__party_libunwind_src_src_UnwindCursor.hpp,v 1.5 2026/05/10 15:30:05 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/libunwind/src/src/UnwindCursor.hpp.orig	2026-04-28 23:05:57.000000000 +0200
+++ third_party/libunwind/src/src/UnwindCursor.hpp
@@ -114,6 +114,8 @@ extern "C" _Unwind_Reason_Code __libunwi
 
 namespace libunwind {
 
+static thread_local UnwindInfoSectionsCache uwis_cache;
+
 #if defined(_LIBUNWIND_SUPPORT_DWARF_UNWIND)
 /// Cache of recently found FDEs.
 template <typename A>
@@ -2776,7 +2778,14 @@ void UnwindCursor<A, R>::setInfoBasedOnI
 
   // Ask address space object to find unwind sections for this pc.
   UnwindInfoSections sects;
-  if (_addressSpace.template findUnwindSections<R>(pc, sects)) {
+  bool have_sects = false;
+  if (uwis_cache.getUnwindInfoSectionsForPC(pc, sects))
+    have_sects = true;
+  else if (_addressSpace.template findUnwindSections<R>(pc, sects)) {
+    uwis_cache.setUnwindInfoSectionsForPC(pc, sects);
+    have_sects = true;
+  }
+  if (have_sects) {
 #if defined(_LIBUNWIND_SUPPORT_COMPACT_UNWIND)
     // If there is a compact unwind encoding table, look there first.
     if (sects.compact_unwind_section != 0) {
