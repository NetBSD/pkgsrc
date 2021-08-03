$NetBSD: patch-src_3rdparty_chromium_ipc_ipc__message__utils.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/ipc/ipc_message_utils.cc.orig	2020-07-08 21:40:45.000000000 +0000
+++ src/3rdparty/chromium/ipc/ipc_message_utils.cc
@@ -356,7 +356,7 @@ void ParamTraits<unsigned int>::Log(cons
   l->append(base::NumberToString(p));
 }
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FUCHSIA) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD) || \
     (defined(OS_ANDROID) && defined(ARCH_CPU_64_BITS))
 void ParamTraits<long>::Log(const param_type& p, std::string* l) {
   l->append(base::NumberToString(p));
