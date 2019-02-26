$NetBSD: patch-third__party_rust_libc_src_unix_bsd_netbsdlike_netbsd_mod.rs,v 1.1 2019/02/26 12:14:12 rin Exp $

Hack for rust/libc 2.43. No need if libc >= 2.45 is imported.

XXX This requires to overwrite checksum field in
XXX third_party/rust/libc/.cargo-checksum.json

--- third_party/rust/libc/src/unix/bsd/netbsdlike/netbsd/mod.rs.orig	2019-02-25 14:11:08.927293182 +0900
+++ third_party/rust/libc/src/unix/bsd/netbsdlike/netbsd/mod.rs	2019-02-25 17:36:14.206597084 +0900
@@ -1,6 +1,5 @@
 use dox::mem;
 
-pub type c_char = i8;
 pub type clock_t = ::c_uint;
 pub type suseconds_t = ::c_int;
 pub type dev_t = u64;
