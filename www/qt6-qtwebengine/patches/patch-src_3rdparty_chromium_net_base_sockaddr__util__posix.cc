$NetBSD: patch-src_3rdparty_chromium_net_base_sockaddr__util__posix.cc,v 1.1 2025/12/21 09:38:34 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/net/base/sockaddr_util_posix.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/net/base/sockaddr_util_posix.cc
@@ -46,7 +46,8 @@ bool FillUnixAddress(const std::string& 
     return true;
   }
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
+  // XXX ?
   // Convert the path given into abstract socket name. It must start with
   // the '\0' character, so we are adding it. |addr_len| must specify the
   // length of the structure exactly, as potentially the socket name may
