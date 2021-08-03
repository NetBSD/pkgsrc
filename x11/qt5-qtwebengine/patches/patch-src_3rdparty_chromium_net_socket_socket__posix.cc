$NetBSD: patch-src_3rdparty_chromium_net_socket_socket__posix.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/net/socket/socket_posix.cc.orig	2020-07-15 18:56:00.000000000 +0000
+++ src/3rdparty/chromium/net/socket/socket_posix.cc
@@ -517,7 +517,7 @@ void SocketPosix::ReadCompleted() {
 }
 
 int SocketPosix::DoWrite(IOBuffer* buf, int buf_len) {
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   // Disable SIGPIPE for this write. Although Chromium globally disables
   // SIGPIPE, the net stack may be used in other consumers which do not do
   // this. MSG_NOSIGNAL is a Linux-only API. On OS X, this is a setsockopt on
