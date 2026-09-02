$NetBSD: patch-rollup_rust_bindings__napi_src_lib.rs,v 1.11 2026/09/02 13:13:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- rollup/rust/bindings_napi/src/lib.rs.orig	2026-05-14 17:17:51.000000000 +0000
+++ rollup/rust/bindings_napi/src/lib.rs
@@ -8,6 +8,8 @@ use std::mem;
   not(all(target_os = "linux", target_arch = "riscv64", target_env = "musl")),
   not(all(target_os = "linux", target_env = "ohos")),
   not(all(target_os = "freebsd", target_arch = "aarch64")),
+  not(all(target_os = "openbsd", target_arch = "aarch64")),
+  not(all(target_os = "netbsd", target_arch = "evbarm")),
   not(debug_assertions)
 ))]
 #[global_allocator]
