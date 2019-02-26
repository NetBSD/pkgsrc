$NetBSD: patch-third__party_rust_libc_src_unix_bsd_netbsdlike_netbsd_other_mod.rs,v 1.1 2019/02/26 12:14:12 rin Exp $

Hack for rust/libc 2.43. No need if libc >= 2.45 is imported.

XXX This requires to overwrite checksum field in
XXX third_party/rust/libc/.cargo-checksum.json

--- third_party/rust/libc/src/unix/bsd/netbsdlike/netbsd/other/mod.rs.orig	2019-02-25 14:01:02.721786754 +0900
+++ third_party/rust/libc/src/unix/bsd/netbsdlike/netbsd/other/mod.rs	2019-02-25 17:36:24.225942932 +0900
@@ -1,5 +1,15 @@
 cfg_if! {
-    if #[cfg(any(target_arch = "sparc64",
+    if #[cfg(any(target_arch = "aarch64",
+                 target_arch = "arm"))] {
+        pub type c_char = u8;
+    } else {
+        pub type c_char = i8;
+    }
+}
+
+cfg_if! {
+    if #[cfg(any(target_arch = "aarch64",
+                 target_arch = "sparc64",
                  target_arch = "x86_64"))] {
         mod b64;
         pub use self::b64::*;
