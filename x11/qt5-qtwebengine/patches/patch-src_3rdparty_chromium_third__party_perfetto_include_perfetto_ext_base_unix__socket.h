$NetBSD: patch-src_3rdparty_chromium_third__party_perfetto_include_perfetto_ext_base_unix__socket.h,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/perfetto/include/perfetto/ext/base/unix_socket.h.orig	2020-06-25 09:34:47.000000000 +0000
+++ src/3rdparty/chromium/third_party/perfetto/include/perfetto/ext/base/unix_socket.h
@@ -321,7 +321,8 @@ class UnixSocket {
   int last_error_ = 0;
   uid_t peer_uid_ = kInvalidUid;
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_NETBSD)
   pid_t peer_pid_ = kInvalidPid;
 #endif
   EventListener* const event_listener_;
