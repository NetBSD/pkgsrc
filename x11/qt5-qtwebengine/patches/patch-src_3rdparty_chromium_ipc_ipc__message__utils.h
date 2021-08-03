$NetBSD: patch-src_3rdparty_chromium_ipc_ipc__message__utils.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/ipc/ipc_message_utils.h.orig	2020-07-08 21:40:45.000000000 +0000
+++ src/3rdparty/chromium/ipc/ipc_message_utils.h
@@ -209,7 +209,7 @@ struct ParamTraits<unsigned int> {
 //   3) Android 64 bit and Fuchsia also have int64_t typedef'd to long.
 // Since we want to support Android 32<>64 bit IPC, as long as we don't have
 // these traits for 32 bit ARM then that'll catch any errors.
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FUCHSIA) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD) || \
     (defined(OS_ANDROID) && defined(ARCH_CPU_64_BITS))
 template <>
 struct ParamTraits<long> {
