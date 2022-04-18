$NetBSD: patch-src_3rdparty_chromium_mojo_public_cpp_platform_socket__utils__posix.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/mojo/public/cpp/platform/socket_utils_posix.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/mojo/public/cpp/platform/socket_utils_posix.cc
@@ -29,7 +29,7 @@ bool IsRecoverableError() {
 }
 
 bool GetPeerEuid(base::PlatformFile fd, uid_t* peer_euid) {
-#if defined(OS_APPLE) || defined(OS_OPENBSD) || defined(OS_FREEBSD)
+#if defined(OS_APPLE) || defined(OS_OPENBSD) || defined(OS_FREEBSD) || defined(OS_NETBSD)
   uid_t socket_euid;
   gid_t socket_gid;
   if (getpeereid(fd, &socket_euid, &socket_gid) < 0) {
