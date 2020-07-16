$NetBSD: patch-third__party_rust_authenticator_src_lib.rs,v 1.2 2020/07/16 14:46:56 riastradh Exp $

Add NetBSD support for U2F.

Submitted upstream:

https://github.com/mozilla/authenticator-rs/pull/116

--- third_party/rust/authenticator/src/lib.rs.orig	2020-07-08 19:27:16.000000000 +0000
+++ third_party/rust/authenticator/src/lib.rs
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
 #[cfg(any(target_os = "openbsd"))]
 #[path = "openbsd/mod.rs"]
 pub mod platform;
@@ -41,6 +45,7 @@ pub mod platform;
     target_os = "linux",
     target_os = "freebsd",
     target_os = "openbsd",
+    target_os = "netbsd",
     target_os = "macos",
     target_os = "windows"
 )))]
