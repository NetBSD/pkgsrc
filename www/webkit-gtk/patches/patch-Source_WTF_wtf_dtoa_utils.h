$NetBSD: patch-Source_WTF_wtf_dtoa_utils.h,v 1.3 2025/10/25 14:45:27 tsutsui Exp $

- fix build errors on NetBSD/earmeb (and earmv7hfeb etc.)

--- Source/WTF/wtf/dtoa/utils.h.orig	2022-06-30 09:49:30.166184200 +0000
+++ Source/WTF/wtf/dtoa/utils.h
@@ -80,7 +80,7 @@ int main(int argc, char** argv) {
 //
 // If it prints "correct" then the architecture should be here, in the "correct" section.
 #if defined(_M_X64) || defined(__x86_64__) || \
-    defined(__ARMEL__) || defined(__avr32__) || defined(_M_ARM) || defined(_M_ARM64) || \
+    defined(__ARMEL__) || defined(__ARMEB__) || defined(__avr32__) || defined(_M_ARM) || defined(_M_ARM64) || \
     defined(__hppa__) || defined(__ia64__) || \
     defined(__mips__) || \
     defined(__powerpc__) || defined(__ppc__) || defined(__ppc64__) || \
