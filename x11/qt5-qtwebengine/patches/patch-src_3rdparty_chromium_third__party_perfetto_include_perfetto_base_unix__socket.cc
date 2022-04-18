$NetBSD: patch-src_3rdparty_chromium_third__party_perfetto_include_perfetto_base_unix__socket.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/third_party/perfetto/src/base/unix_socket.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/third_party/perfetto/src/base/unix_socket.cc
@@ -37,7 +37,7 @@
 #include "perfetto/ext/base/string_utils.h"
 #include "perfetto/ext/base/utils.h"
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) || PERFETTO_BUILDFLAG(PERFETTO_OS_NETBSD)
 #include <sys/ucred.h>
 #endif
 
@@ -634,6 +634,14 @@ void UnixSocket::ReadPeerCredentials() {
   PERFETTO_CHECK(res == 0);
   peer_uid_ = user_cred.uid;
   peer_pid_ = user_cred.pid;
+#elif PERFETTO_BUILDFLAG(PERFETTO_OS_NETBSD)
+  struct unpcbid user_cred;
+  socklen_t len = sizeof(user_cred);
+  int fd = sock_raw_.fd();
+  int res = getsockopt(fd, 0, LOCAL_PEEREID, &user_cred, &len);
+  PERFETTO_CHECK(res == 0);
+  peer_uid_ = user_cred.unp_euid;
+  peer_pid_ = user_cred.unp_pid;
 #else
   struct xucred user_cred;
   socklen_t len = sizeof(user_cred);
