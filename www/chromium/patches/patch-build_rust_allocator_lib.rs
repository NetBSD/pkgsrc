$NetBSD: patch-build_rust_allocator_lib.rs,v 1.4 2025/10/16 19:43:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- build/rust/allocator/lib.rs.orig	2025-10-13 21:41:26.000000000 +0000
+++ build/rust/allocator/lib.rs
@@ -96,6 +96,12 @@ mod both_allocators {
         0
     }
 
+    // TODO(crbug.com/422538133) Remove after rolling past
+    // https://github.com/rust-lang/rust/pull/141061
+    #[no_mangle]
+    #[linkage = "weak"]
+    static __rust_no_alloc_shim_is_unstable: u8 = 0;
+
     // Mangle the symbol name as rustc expects.
     // TODO(crbug.com/440481922): Remove this after rolling past https://github.com/rust-lang/rust/pull/143387
     #[rustc_std_internal_symbol]
