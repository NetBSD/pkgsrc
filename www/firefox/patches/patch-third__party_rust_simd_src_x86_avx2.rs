$NetBSD: patch-third__party_rust_simd_src_x86_avx2.rs,v 1.1.2.2 2018/03/22 06:56:21 spz Exp $

--- third_party/rust/simd/src/x86/avx2.rs.orig	2018-03-10 02:54:17.000000000 +0000
+++ third_party/rust/simd/src/x86/avx2.rs
@@ -42,7 +42,7 @@ extern "platform-intrinsic" {
     fn x86_mm256_packus_epi32(x: i32x8, y: i32x8) -> u16x16;
     fn x86_mm256_permutevar8x32_epi32(x: i32x8, y: i32x8) -> i32x8;
     fn x86_mm256_permutevar8x32_ps(x: f32x8, y: i32x8) -> f32x8;
-    fn x86_mm256_sad_epu8(x: u8x32, y: u8x32) -> u8x32;
+    fn x86_mm256_sad_epu8(x: u8x32, y: u8x32) -> u64x4;
     fn x86_mm256_shuffle_epi8(x: i8x32, y: i8x32) -> i8x32;
     fn x86_mm256_sign_epi8(x: i8x32, y: i8x32) -> i8x32;
     fn x86_mm256_sign_epi16(x: i16x16, y: i16x16) -> i16x16;
