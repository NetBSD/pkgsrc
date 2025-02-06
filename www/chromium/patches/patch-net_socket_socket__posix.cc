$NetBSD: patch-net_socket_socket__posix.cc,v 1.1 2025/02/06 09:58:15 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/socket/socket_posix.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ net/socket/socket_posix.cc
@@ -516,7 +516,7 @@ void SocketPosix::ReadCompleted() {
 }
 
 int SocketPosix::DoWrite(IOBuffer* buf, int buf_len) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // Disable SIGPIPE for this write. Although Chromium globally disables
   // SIGPIPE, the net stack may be used in other consumers which do not do
   // this. MSG_NOSIGNAL is a Linux-only API. On OS X, this is a setsockopt on
