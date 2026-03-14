$NetBSD: patch-net_base_sockaddr__util__posix.cc,v 1.16 2026/03/14 12:40:37 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/base/sockaddr_util_posix.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ net/base/sockaddr_util_posix.cc
@@ -51,7 +51,8 @@ bool FillUnixAddress(std::string_view so
     return true;
   }
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
+  // XXX ?
   // Convert the path given into abstract socket name. It must start with
   // the '\0' character, skip over it, as it should already be zero. `addr_len`
   // must specify the length of the structure exactly, as potentially the socket
