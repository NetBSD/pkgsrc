$NetBSD: patch-platform_media_libvpx_config_linux_arm64_vpx__config.asm,v 1.1 2026/03/15 10:10:21 nia Exp $

From e502735eb2609befcdf0761e9c59826d8555e5be Mon Sep 17 00:00:00 2001
From: Basilisk-Dev <basiliskdev@protonmail.com>
Date: Wed, 11 Mar 2026 12:21:28 -0400
Subject: [PATCH] Issue #2993 - only use SVE instructions on Apple Silicon

--- platform/media/libvpx/config/linux/arm64/vpx_config.asm.orig	2026-03-01 22:37:59.000000000 +0000
+++ platform/media/libvpx/config/linux/arm64/vpx_config.asm
@@ -12,8 +12,8 @@
 .equ HAVE_NEON ,  1
 .equ HAVE_NEON_DOTPROD ,  1
 .equ HAVE_NEON_I8MM ,  1
-.equ HAVE_SVE ,  1
-.equ HAVE_SVE2 ,  1
+.equ HAVE_SVE ,  0
+.equ HAVE_SVE2 ,  0
 .equ HAVE_MIPS32 ,  0
 .equ HAVE_DSPR2 ,  0
 .equ HAVE_MSA ,  0
