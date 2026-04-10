$NetBSD: patch-rollup_rust_bindings__napi_src_lib.rs,v 1.3 2026/04/10 17:31:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- rollup/rust/bindings_napi/src/lib.rs.orig	2024-09-21 06:00:56.000000000 +0000
+++ rollup/rust/bindings_napi/src/lib.rs
@@ -4,6 +4,9 @@ use parse_ast::parse_ast;
 
 #[cfg(all(
   not(all(target_os = "linux", target_env = "musl", target_arch = "aarch64")),
+  not(all(target_os = "freebsd", target_arch = "aarch64")),
+  not(all(target_os = "openbsd", target_arch = "aarch64")),
+  not(all(target_os = "netbsd", target_arch = "evbarm")),
   not(debug_assertions)
 ))]
 #[global_allocator]
