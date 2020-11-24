$NetBSD: patch-src_3rdparty_double-conversion_include_double-conversion_utils.h,v 1.1 2020/11/24 09:35:18 tsutsui Exp $

- fix a build error on NetBSD/sh3el.

--- src/3rdparty/double-conversion/include/double-conversion/utils.h.orig	2020-09-02 10:15:07.000000000 +0000
+++ src/3rdparty/double-conversion/include/double-conversion/utils.h
@@ -97,7 +97,7 @@ int main(int argc, char** argv) {
     defined(__powerpc__) || defined(__ppc__) || defined(__ppc64__) || \
     defined(_POWER) || defined(_ARCH_PPC) || defined(_ARCH_PPC64) || \
     defined(__sparc__) || defined(__sparc) || defined(__s390__) || \
-    defined(__SH4__) || defined(__alpha__) || \
+    defined(__sh__) || defined(__SH4__) || defined(__alpha__) || \
     defined(_MIPS_ARCH_MIPS32R2) || defined(__ARMEB__) ||\
     defined(__AARCH64EL__) || defined(__aarch64__) || defined(__AARCH64EB__) || \
     defined(__riscv) || \
