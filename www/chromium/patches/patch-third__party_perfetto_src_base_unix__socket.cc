$NetBSD: patch-third__party_perfetto_src_base_unix__socket.cc,v 1.1 2025/02/06 09:58:27 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/src/base/unix_socket.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/perfetto/src/base/unix_socket.cc
@@ -44,7 +44,7 @@
 #include <unistd.h>
 #endif
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) || defined(__FreeBSD__) || defined(__NetBSD__)
 #include <sys/ucred.h>
 #endif
 
@@ -917,15 +917,27 @@ void UnixSocket::ReadPeerCredentialsPosi
     return;
   PERFETTO_CHECK(peer_cred_mode_ != SockPeerCredMode::kIgnore);
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+#if !defined(__FreeBSD__) && !defined(__NetBSD__) && PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
+  struct sockpeercred user_cred;
+#else
   struct ucred user_cred;
+#endif
   socklen_t len = sizeof(user_cred);
   int fd = sock_raw_.fd();
   int res = getsockopt(fd, SOL_SOCKET, SO_PEERCRED, &user_cred, &len);
   PERFETTO_CHECK(res == 0);
   peer_uid_ = user_cred.uid;
   peer_pid_ = user_cred.pid;
+#elif defined(__NetBSD__)
+  struct unpcbid user_cred;
+  socklen_t len = sizeof(user_cred);
+  int fd = sock_raw_.fd();
+  int res = getsockopt(fd, 0, LOCAL_PEEREID, &user_cred, &len);
+  PERFETTO_CHECK(res == 0);
+  peer_uid_ = user_cred.unp_euid;
+  peer_pid_ = user_cred.unp_pid;
 #elif PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
   struct xucred user_cred;
   socklen_t len = sizeof(user_cred);
