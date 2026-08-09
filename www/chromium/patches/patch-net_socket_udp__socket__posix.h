$NetBSD: patch-net_socket_udp__socket__posix.h,v 1.1 2026/08/09 06:31:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/socket/udp_socket_posix.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ net/socket/udp_socket_posix.h
@@ -409,7 +409,7 @@ class NET_EXPORT UDPSocketPosix {
       size_t buf_len,
       size_t maximum_packet_size);
   // recvmmsg() is only available on Linux, ChromeOS, and Android.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   base::expected<DatagramsMetadata, Error> InternalRecvMmsg(
       IOBuffer* buffer,
       size_t num_messages,
