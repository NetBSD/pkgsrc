$NetBSD: patch-third__party_rust_libloading_build.rs,v 1.1 2018/06/28 14:04:10 ryoon Exp $

Support SunOS.

--- third_party/rust/libloading/build.rs.orig	2018-06-05 19:47:45.000000000 +0000
+++ third_party/rust/libloading/build.rs
@@ -9,7 +9,7 @@ fn main(){
         // netbsd claims dl* will be available to any dynamically linked binary, but I haven’t
         // found any libraries that have to be linked to on other platforms.
         // What happens if the executable is not linked up dynamically?
-        Ok("openbsd") | Ok("bitrig") | Ok("netbsd") | Ok("macos") | Ok("ios") => {}
+        Ok("openbsd") | Ok("bitrig") | Ok("netbsd") | Ok("macos") | Ok("ios") | Ok("solaris") => {}
         // dependencies come with winapi
         Ok("windows") => {}
         tos => {
