$NetBSD: patch-net_socket_socks5__client__socket.cc,v 1.18 2026/04/21 15:21:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/socket/socks5_client_socket.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ net/socket/socks5_client_socket.cc
@@ -23,6 +23,9 @@
 #include "net/log/net_log_event_type.h"
 #include "net/traffic_annotation/network_traffic_annotation.h"
 
+#include <sys/types.h>
+#include <netinet/in.h>
+
 namespace net {
 
 const unsigned int SOCKS5ClientSocket::kGreetReadHeaderSize = 2;
