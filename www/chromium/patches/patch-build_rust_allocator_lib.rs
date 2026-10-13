$NetBSD: patch-build_rust_allocator_lib.rs,v 1.25 2026/10/13 13:16:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- build/rust/allocator/lib.rs.orig	2026-10-06 00:06:58.000000000 +0000
+++ build/rust/allocator/lib.rs
@@ -111,6 +111,12 @@ mod both_allocators {
         0
     }
 
+    // TODO(crbug.com/440481922): Remove this after rolling past https://github.com/rust-lang/rust/pull/143387
+    #[rustc_std_internal_symbol]
+    #[allow(non_upper_case_globals)]
+    #[linkage = "weak"]
+    static __rust_alloc_error_handler_should_panic: u8 = 0;
+
     // Mangle the symbol name as rustc expects.
     #[rustc_std_internal_symbol]
     #[allow(non_upper_case_globals)]
