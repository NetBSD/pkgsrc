$NetBSD: patch-third__party_perfetto_src_base_unix__socket.cc,v 1.18 2026/04/21 15:21:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/src/base/unix_socket.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ third_party/perfetto/src/base/unix_socket.cc
@@ -48,7 +48,8 @@
 #endif
 
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_NETBSD)
 #include <sys/ucred.h>
 #endif
 
@@ -1071,9 +1072,16 @@ void UnixSocket::ReadPeerCredentialsPosi
   ignore_result(peer_gid);
   PERFETTO_CHECK(res == 0);
   // There is no pid when obtaining peer credentials for QNX
-#elif PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#elif (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_NETBSD)
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD)
+  struct sockpeercred user_cred;
+#else
   struct ucred user_cred;
+#endif
   socklen_t len = sizeof(user_cred);
   int fd = sock_raw_.fd();
   int res = getsockopt(fd, SOL_SOCKET, SO_PEERCRED, &user_cred, &len);
@@ -1088,6 +1096,14 @@ void UnixSocket::ReadPeerCredentialsPosi
   PERFETTO_CHECK(res == 0 && user_cred.cr_version == XUCRED_VERSION);
   peer_uid_ = static_cast<uid_t>(user_cred.cr_uid);
   // There is no pid in the LOCAL_PEERCREDS for MacOS / FreeBSD.
+#elif PERFETTO_BUILDFLAG(PERFETTO_OS_NETBSD)
+  struct unpcbid user_cred;
+  socklen_t len = sizeof(user_cred);
+  int fd = sock_raw_.fd();
+  int res = getsockopt(fd, 0, LOCAL_PEEREID, &user_cred, &len);
+  PERFETTO_CHECK(res == 0);
+  peer_uid_ = user_cred.unp_euid;
+  peer_pid_ = user_cred.unp_pid;
 #endif
 }
 #endif  // !OS_WIN
