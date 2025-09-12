$NetBSD: patch-base_message__loop_message__pump__epoll.cc,v 1.7 2025/09/12 16:02:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/message_loop/message_pump_epoll.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ base/message_loop/message_pump_epoll.cc
@@ -49,7 +49,7 @@ std::atomic_bool g_use_batched_version =
 std::atomic_bool g_use_poll = false;
 
 constexpr std::pair<uint32_t, short int> kEpollToPollEvents[] = {
-    {EPOLLIN, POLLIN},   {EPOLLOUT, POLLOUT}, {EPOLLRDHUP, POLLRDHUP},
+    {EPOLLIN, POLLIN},   {EPOLLOUT, POLLOUT},
     {EPOLLPRI, POLLPRI}, {EPOLLERR, POLLERR}, {EPOLLHUP, POLLHUP}};
 
 void SetEventsForPoll(const uint32_t epoll_events, struct pollfd* poll_entry) {
