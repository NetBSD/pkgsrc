$NetBSD: patch-deps_harfbuzz_build.rs,v 1.1 2026/04/03 15:37:48 wiz Exp $

Use dependencies from pkgsrc.

--- deps/harfbuzz/build.rs.orig	2026-04-03 14:44:33.240905456 +0000
+++ deps/harfbuzz/build.rs
@@ -65,6 +65,8 @@ fn main() {
 }
 
 fn main() {
+    println!("cargo:rustc-link-lib=harfbuzz");
+    return;
     harfbuzz();
     let out_dir = env::var("OUT_DIR").unwrap();
     println!("cargo:outdir={}", out_dir);
