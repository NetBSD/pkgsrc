$NetBSD: patch-third__party_skia_rust_png_FFI.rs,v 1.6 2026/01/19 16:14:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/skia/rust/png/FFI.rs.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/skia/rust/png/FFI.rs
@@ -222,6 +222,7 @@ mod ffi {
         type StreamWriter;
         fn write(self: &mut StreamWriter, data: &[u8]) -> EncodingResult;
         fn finish_encoding(stream_writer: Box<StreamWriter>) -> EncodingResult;
+        fn initialize_cpudetect();
     }
 }
 
@@ -929,3 +930,11 @@ fn new_writer(
 fn finish_encoding(stream_writer: Box<StreamWriter>) -> ffi::EncodingResult {
     stream_writer.0.finish().as_ref().err().into()
 }
+
+#[allow(unused_variables)]
+fn initialize_cpudetect() {
+    #[cfg(any(target_arch = "aarch64", target_arch = "arm64ec"))]
+    let a = std::arch::is_aarch64_feature_detected!("crc");
+    #[cfg(any(target_arch = "x86", target_arch = "x86_64"))]
+    let a = std::arch::is_x86_feature_detected!("sse2");
+}
