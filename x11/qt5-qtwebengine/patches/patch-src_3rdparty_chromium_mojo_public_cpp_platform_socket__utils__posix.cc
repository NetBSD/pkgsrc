$NetBSD: patch-src_3rdparty_chromium_mojo_public_cpp_platform_socket__utils__posix.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/mojo/public/cpp/platform/socket_utils_posix.cc.orig	2020-07-15 18:55:59.000000000 +0000
+++ src/3rdparty/chromium/mojo/public/cpp/platform/socket_utils_posix.cc
@@ -29,7 +29,7 @@ bool IsRecoverableError() {
 }
 
 bool GetPeerEuid(base::PlatformFile fd, uid_t* peer_euid) {
-#if defined(OS_MACOSX) || defined(OS_OPENBSD) || defined(OS_FREEBSD)
+#if defined(OS_MACOSX) || defined(OS_OPENBSD) || defined(OS_FREEBSD) || defined(OS_NETBSD)
   uid_t socket_euid;
   gid_t socket_gid;
   if (getpeereid(fd, &socket_euid, &socket_gid) < 0) {
