$NetBSD: patch-platform_media_libvpx_config_linux_arm64_vp9__rtcd.h,v 1.1 2026/03/15 10:10:21 nia Exp $

From e502735eb2609befcdf0761e9c59826d8555e5be Mon Sep 17 00:00:00 2001
From: Basilisk-Dev <basiliskdev@protonmail.com>
Date: Wed, 11 Mar 2026 12:21:28 -0400
Subject: [PATCH] Issue #2993 - only use SVE instructions on Apple Silicon

--- platform/media/libvpx/config/linux/arm64/vp9_rtcd.h.orig	2026-03-01 22:37:59.000000000 +0000
+++ platform/media/libvpx/config/linux/arm64/vp9_rtcd.h
@@ -48,12 +48,16 @@ extern "C" {
 
 int64_t vp9_block_error_c(const tran_low_t *coeff, const tran_low_t *dqcoeff, intptr_t block_size, int64_t *ssz);
 int64_t vp9_block_error_neon(const tran_low_t *coeff, const tran_low_t *dqcoeff, intptr_t block_size, int64_t *ssz);
+#if HAVE_SVE
 int64_t vp9_block_error_sve(const tran_low_t *coeff, const tran_low_t *dqcoeff, intptr_t block_size, int64_t *ssz);
+#endif
 RTCD_EXTERN int64_t (*vp9_block_error)(const tran_low_t *coeff, const tran_low_t *dqcoeff, intptr_t block_size, int64_t *ssz);
 
 int64_t vp9_block_error_fp_c(const tran_low_t *coeff, const tran_low_t *dqcoeff, int block_size);
 int64_t vp9_block_error_fp_neon(const tran_low_t *coeff, const tran_low_t *dqcoeff, int block_size);
+#if HAVE_SVE
 int64_t vp9_block_error_fp_sve(const tran_low_t *coeff, const tran_low_t *dqcoeff, int block_size);
+#endif
 RTCD_EXTERN int64_t (*vp9_block_error_fp)(const tran_low_t *coeff, const tran_low_t *dqcoeff, int block_size);
 
 int vp9_diamond_search_sad_c(const struct macroblock *x, const struct search_site_config *cfg,  struct mv *ref_mv, uint32_t start_mv_sad, struct mv *best_mv, int search_param, int sad_per_bit, int *num00, const struct vp9_sad_table *sad_fn_ptr, const struct mv *center_mv);
@@ -112,9 +116,13 @@ static void setup_rtcd_internal(void)
     (void)flags;
 
     vp9_block_error = vp9_block_error_neon;
+#if HAVE_SVE
     if (flags & HAS_SVE) vp9_block_error = vp9_block_error_sve;
+#endif
     vp9_block_error_fp = vp9_block_error_fp_neon;
+#if HAVE_SVE
     if (flags & HAS_SVE) vp9_block_error_fp = vp9_block_error_fp_sve;
+#endif
 }
 #endif
 
