$NetBSD: patch-platform_media_libvpx_config_linux_arm64_vpx__dsp__rtcd.h,v 1.1 2026/03/15 10:10:21 nia Exp $

From e502735eb2609befcdf0761e9c59826d8555e5be Mon Sep 17 00:00:00 2001
From: Basilisk-Dev <basiliskdev@protonmail.com>
Date: Wed, 11 Mar 2026 12:21:28 -0400
Subject: [PATCH] Issue #2993 - only use SVE instructions on Apple Silicon

--- platform/media/libvpx/config/linux/arm64/vpx_dsp_rtcd.h.orig	2026-03-01 22:37:59.000000000 +0000
+++ platform/media/libvpx/config/linux/arm64/vpx_dsp_rtcd.h
@@ -926,7 +926,9 @@ void vpx_subtract_block_neon(int rows, i
 
 uint64_t vpx_sum_squares_2d_i16_c(const int16_t *src, int stride, int size);
 uint64_t vpx_sum_squares_2d_i16_neon(const int16_t *src, int stride, int size);
+#if HAVE_SVE
 uint64_t vpx_sum_squares_2d_i16_sve(const int16_t *src, int stride, int size);
+#endif
 RTCD_EXTERN uint64_t (*vpx_sum_squares_2d_i16)(const int16_t *src, int stride, int size);
 
 void vpx_tm_predictor_16x16_c(uint8_t *dst, ptrdiff_t stride, const uint8_t *above, const uint8_t *left);
@@ -1160,7 +1162,9 @@ static void setup_rtcd_internal(void)
     vpx_sse = vpx_sse_neon;
     if (flags & HAS_NEON_DOTPROD) vpx_sse = vpx_sse_neon_dotprod;
     vpx_sum_squares_2d_i16 = vpx_sum_squares_2d_i16_neon;
+#if HAVE_SVE
     if (flags & HAS_SVE) vpx_sum_squares_2d_i16 = vpx_sum_squares_2d_i16_sve;
+#endif
     vpx_variance16x16 = vpx_variance16x16_neon;
     if (flags & HAS_NEON_DOTPROD) vpx_variance16x16 = vpx_variance16x16_neon_dotprod;
     vpx_variance16x32 = vpx_variance16x32_neon;
