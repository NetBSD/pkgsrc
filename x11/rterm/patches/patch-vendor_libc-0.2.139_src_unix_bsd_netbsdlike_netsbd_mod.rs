$NetBSD: patch-vendor_libc-0.2.139_src_unix_bsd_netbsdlike_netsbd_mod.rs,v 1.1 2024/01/20 23:27:51 he Exp $

Add use of spec for NetBSD/riscv64.

--- ../vendor/libc-0.2.139/src/unix/bsd/netbsdlike/netbsd/mod.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/libc-0.2.139/src/unix/bsd/netbsdlike/netbsd/mod.rs
@@ -3068,6 +3068,9 @@ cfg_if! {
     } else if #[cfg(target_arch = "x86")] {
         mod x86;
         pub use self::x86::*;
+    } else if #[cfg(target_arch = "riscv64")] {
+        mod riscv64;
+        pub use self::riscv64::*;
     } else {
         // Unknown target_arch
     }
