$NetBSD: patch-mojo_public_cpp_platform_socket__utils__posix.cc,v 1.11 2025/12/11 09:13:40 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- mojo/public/cpp/platform/socket_utils_posix.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ mojo/public/cpp/platform/socket_utils_posix.cc
@@ -30,7 +30,7 @@ bool IsRecoverableError() {
 }
 
 bool GetPeerEuid(base::PlatformFile fd, uid_t* peer_euid) {
-#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_OPENBSD) || BUILDFLAG(IS_FREEBSD)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_OPENBSD) || BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_NETBSD)
   uid_t socket_euid;
   gid_t socket_gid;
   if (getpeereid(fd, &socket_euid, &socket_gid) < 0) {
