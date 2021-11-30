$NetBSD: patch-third__party_rust_packed__simd_src_lib.rs,v 1.1 2021/11/30 15:41:24 ryoon Exp $

* Fix build with lang/rust-1.56.1. From www/firefox-95.0.

--- third_party/rust/packed_simd/src/lib.rs.orig	2021-08-08 13:02:00.000000000 +0000
+++ third_party/rust/packed_simd/src/lib.rs
@@ -199,8 +199,9 @@
 //!   Numeric casts are not very "precise": sometimes lossy, sometimes value
 //!   preserving, etc.
 
+#![cfg_attr(const_generics, feature(const_generics))]
+#![cfg_attr(not(const_generics), feature(adt_const_params))]
 #![feature(
-    const_generics,
     repr_simd,
     rustc_attrs,
     platform_intrinsics,
