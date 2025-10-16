$NetBSD: patch-third__party_skia_experimental_rust__png_ffi_FFI.rs,v 1.1 2025/10/16 19:43:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/skia/experimental/rust_png/ffi/FFI.rs.orig	2025-10-13 21:41:26.000000000 +0000
+++ third_party/skia/experimental/rust_png/ffi/FFI.rs
@@ -219,6 +219,7 @@ mod ffi {
         type StreamWriter;
         fn write(self: &mut StreamWriter, data: &[u8]) -> EncodingResult;
         fn finish_encoding(stream_writer: Box<StreamWriter>) -> EncodingResult;
+        fn initialize_cpudetect();
     }
 }
 
@@ -884,3 +885,11 @@ fn new_writer(
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
