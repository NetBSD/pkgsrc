$NetBSD: patch-src_3rdparty_chromium_base_message__loop_message__pump__epoll.cc,v 1.1 2025/12/21 09:38:14 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/message_loop/message_pump_epoll.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/base/message_loop/message_pump_epoll.cc
@@ -42,7 +42,7 @@ std::atomic_bool g_use_batched_version =
 std::atomic_bool g_use_poll = false;
 
 constexpr std::pair<uint32_t, short int> kEpollToPollEvents[] = {
-    {EPOLLIN, POLLIN},   {EPOLLOUT, POLLOUT}, {EPOLLRDHUP, POLLRDHUP},
+    {EPOLLIN, POLLIN},   {EPOLLOUT, POLLOUT},
     {EPOLLPRI, POLLPRI}, {EPOLLERR, POLLERR}, {EPOLLHUP, POLLHUP}};
 
 void SetEventsForPoll(const uint32_t epoll_events, struct pollfd* poll_entry) {
