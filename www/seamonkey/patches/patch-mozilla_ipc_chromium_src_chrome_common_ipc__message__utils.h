$NetBSD: patch-mozilla_ipc_chromium_src_chrome_common_ipc__message__utils.h,v 1.4 2012/09/06 12:08:51 ryoon Exp $

--- mozilla/ipc/chromium/src/chrome/common/ipc_message_utils.h.orig	2012-08-27 04:49:15.000000000 +0000
+++ mozilla/ipc/chromium/src/chrome/common/ipc_message_utils.h
@@ -195,7 +195,7 @@ struct ParamTraits<unsigned long long> {
 };
 #endif
 
-#if !(defined(OS_MACOSX) || defined(OS_OPENBSD) || defined(OS_WIN) || (defined(OS_LINUX) && defined(ARCH_CPU_64_BITS)) || defined(ARCH_CPU_S390))
+#if !(defined(OS_MACOSX) || defined(OS_OPENBSD) || defined(OS_WIN) || ((defined(OS_BSD) || defined(OS_LINUX)) && defined(ARCH_CPU_64_BITS)) || defined(ARCH_CPU_S390))
 // There size_t is a synonym for |unsigned long| ...
 template <>
 struct ParamTraits<size_t> {
@@ -248,7 +248,7 @@ struct ParamTraits<uint32> {
 };
 #endif  // defined(OS_MACOSX)
 
-#if !(defined(OS_LINUX) && defined(ARCH_CPU_64_BITS))
+#if !((defined(OS_BSD) || defined(OS_LINUX)) && defined(ARCH_CPU_64_BITS))
 // int64 is |long int| on 64-bit systems, uint64 is |unsigned long|
 template <>
 struct ParamTraits<int64> {
