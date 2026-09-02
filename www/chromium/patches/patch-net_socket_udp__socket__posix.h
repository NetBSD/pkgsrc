$NetBSD: patch-net_socket_udp__socket__posix.h,v 1.2 2026/09/02 13:13:33 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/socket/udp_socket_posix.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ net/socket/udp_socket_posix.h
@@ -451,7 +451,7 @@ class NET_EXPORT UDPSocketPosix {
       size_t maximum_packet_size);
 
   // recvmmsg() and GRO are only available on Linux, ChromeOS, and Android.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   base::expected<DatagramsMetadata, Error> InternalReadMultipleWithGro(
       IOBuffer* buffer,
       size_t buf_len,
