$NetBSD: patch-src_3rdparty_chromium_third__party_swiftshader_third__party_llvm-10.0_configs_netbsd_include_llvm_Config_abi-breaking.h,v 1.1 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/third_party/swiftshader/third_party/llvm-10.0/configs/netbsd/include/llvm/Config/abi-breaking.h.orig	2020-07-23 07:09:16.381643815 +0000
+++ src/3rdparty/chromium/third_party/swiftshader/third_party/llvm-10.0/configs/netbsd/include/llvm/Config/abi-breaking.h
@@ -0,0 +1,50 @@
+/*===------- llvm/Config/abi-breaking.h - llvm configuration -------*- C -*-===*/
+/*                                                                            */
+/*                     The LLVM Compiler Infrastructure                       */
+/*                                                                            */
+/* This file is distributed under the University of Illinois Open Source      */
+/* License. See LICENSE.TXT for details.                                      */
+/*                                                                            */
+/*===----------------------------------------------------------------------===*/
+
+/* This file controls the C++ ABI break introduced in LLVM public header. */
+
+#ifndef LLVM_ABI_BREAKING_CHECKS_H
+#define LLVM_ABI_BREAKING_CHECKS_H
+
+/* Define to enable checks that alter the LLVM C++ ABI */
+#define LLVM_ENABLE_ABI_BREAKING_CHECKS 1
+
+/* Define to enable reverse iteration of unordered llvm containers */
+#define LLVM_ENABLE_REVERSE_ITERATION 0
+
+/* Allow selectively disabling link-time mismatch checking so that header-only
+   ADT content from LLVM can be used without linking libSupport. */
+#if !LLVM_DISABLE_ABI_BREAKING_CHECKS_ENFORCING
+
+// ABI_BREAKING_CHECKS protection: provides link-time failure when clients build
+// mismatch with LLVM
+#if defined(_MSC_VER)
+// Use pragma with MSVC
+#define LLVM_XSTR(s) LLVM_STR(s)
+#define LLVM_STR(s) #s
+#pragma detect_mismatch("LLVM_ENABLE_ABI_BREAKING_CHECKS", LLVM_XSTR(LLVM_ENABLE_ABI_BREAKING_CHECKS))
+#undef LLVM_XSTR
+#undef LLVM_STR
+#elif defined(_WIN32) || defined(__CYGWIN__) // Win32 w/o #pragma detect_mismatch
+// FIXME: Implement checks without weak.
+#elif defined(__cplusplus)
+namespace llvm {
+#if LLVM_ENABLE_ABI_BREAKING_CHECKS
+extern int EnableABIBreakingChecks;
+__attribute__((weak, visibility ("hidden"))) int *VerifyEnableABIBreakingChecks = &EnableABIBreakingChecks;
+#else
+extern int DisableABIBreakingChecks;
+__attribute__((weak, visibility ("hidden"))) int *VerifyDisableABIBreakingChecks = &DisableABIBreakingChecks;
+#endif
+}
+#endif // _MSC_VER
+
+#endif // LLVM_DISABLE_ABI_BREAKING_CHECKS_ENFORCING
+
+#endif
