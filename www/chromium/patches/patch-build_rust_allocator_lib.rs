$NetBSD: patch-build_rust_allocator_lib.rs,v 1.5 2025/11/04 14:55:30 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- build/rust/allocator/lib.rs.orig	2025-10-24 16:42:30.000000000 +0000
+++ build/rust/allocator/lib.rs
@@ -97,6 +97,19 @@ mod both_allocators {
     }
 
     // Mangle the symbol name as rustc expects.
+    // TODO(crbug.com/440481922): Remove this after rolling past https://github.com/rust-lang/rust/pull/143387
+    #[rustc_std_internal_symbol]
+    #[allow(non_upper_case_globals)]
+    #[linkage = "weak"]
+    static __rust_alloc_error_handler_should_panic: u8 = 0;
+
+    // TODO(crbug.com/422538133) Remove after rolling past
+    // https://github.com/rust-lang/rust/pull/141061
+    #[no_mangle]
+    #[linkage = "weak"]
+    static __rust_no_alloc_shim_is_unstable: u8 = 0;
+
+    // Mangle the symbol name as rustc expects.
     #[rustc_std_internal_symbol]
     #[allow(non_upper_case_globals)]
     #[linkage = "weak"]
