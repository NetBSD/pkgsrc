$NetBSD: patch-src_3rdparty_chromium_ipc_ipc__message__utils.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/ipc/ipc_message_utils.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/ipc/ipc_message_utils.cc
@@ -357,7 +357,7 @@ void ParamTraits<unsigned int>::Log(cons
 }
 
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_FUCHSIA) || (defined(OS_ANDROID) && defined(ARCH_CPU_64_BITS))
+    defined(OS_FUCHSIA) || defined(OS_BSD) || (defined(OS_ANDROID) && defined(ARCH_CPU_64_BITS))
 void ParamTraits<long>::Log(const param_type& p, std::string* l) {
   l->append(base::NumberToString(p));
 }
