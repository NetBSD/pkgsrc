$NetBSD: patch-src_3rdparty_chromium_ipc_ipc__message__utils.h,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/ipc/ipc_message_utils.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/ipc/ipc_message_utils.h
@@ -210,7 +210,7 @@ struct ParamTraits<unsigned int> {
 // Since we want to support Android 32<>64 bit IPC, as long as we don't have
 // these traits for 32 bit ARM then that'll catch any errors.
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_FUCHSIA) || (defined(OS_ANDROID) && defined(ARCH_CPU_64_BITS))
+    defined(OS_FUCHSIA) || defined(OS_BSD) || (defined(OS_ANDROID) && defined(ARCH_CPU_64_BITS))
 template <>
 struct ParamTraits<long> {
   typedef long param_type;
