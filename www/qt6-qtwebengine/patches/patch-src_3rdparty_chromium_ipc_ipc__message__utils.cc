$NetBSD: patch-src_3rdparty_chromium_ipc_ipc__message__utils.cc,v 1.1 2025/12/21 09:38:31 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ipc/ipc_message_utils.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/ipc/ipc_message_utils.cc
@@ -399,7 +399,7 @@ void ParamTraits<unsigned int>::Log(cons
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_FUCHSIA) ||                                              \
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD) ||                         \
     (BUILDFLAG(IS_ANDROID) && defined(ARCH_CPU_64_BITS))
 void ParamTraits<long>::Log(const param_type& p, std::string* l) {
   l->append(base::NumberToString(p));
