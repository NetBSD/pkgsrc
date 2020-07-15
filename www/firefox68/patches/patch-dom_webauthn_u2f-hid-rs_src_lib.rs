$NetBSD: patch-dom_webauthn_u2f-hid-rs_src_lib.rs,v 1.1 2020/07/15 19:52:23 riastradh Exp $

Add NetBSD support for U2F.

--- dom/webauthn/u2f-hid-rs/src/lib.rs.orig	2020-06-22 22:55:03.000000000 +0000
+++ dom/webauthn/u2f-hid-rs/src/lib.rs
@@ -5,7 +5,7 @@
 #[macro_use]
 mod util;
 
-#[cfg(any(target_os = "linux", target_os = "freebsd"))]
+#[cfg(any(target_os = "linux", target_os = "freebsd", target_os = "netbsd"))]
 pub mod hidproto;
 
 #[cfg(any(target_os = "linux"))]
@@ -22,6 +22,10 @@ extern crate devd_rs;
 #[path = "freebsd/mod.rs"]
 pub mod platform;
 
+#[cfg(any(target_os = "netbsd"))]
+#[path = "netbsd/mod.rs"]
+pub mod platform;
+
 #[cfg(any(target_os = "macos"))]
 extern crate core_foundation;
 
@@ -36,6 +40,7 @@ pub mod platform;
 #[cfg(not(any(
     target_os = "linux",
     target_os = "freebsd",
+    target_os = "netbsd",
     target_os = "macos",
     target_os = "windows"
 )))]
