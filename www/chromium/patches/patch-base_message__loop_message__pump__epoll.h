$NetBSD: patch-base_message__loop_message__pump__epoll.h,v 1.23 2026/09/02 13:13:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/message_loop/message_pump_epoll.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ base/message_loop/message_pump_epoll.h
@@ -49,7 +49,11 @@ namespace base {
 // Caveat: Since both we and the kernel need to walk the list of all fds at
 // every call, don't do it when we have too many FDs.
 BASE_FEATURE(kUsePollForMessagePumpEpoll,
+#if BUILDFLAG(IS_BSD)
+             base::FEATURE_ENABLED_BY_DEFAULT);
+#else
              base::FEATURE_DISABLED_BY_DEFAULT);
+#endif
 
 // A MessagePump implementation suitable for I/O message loops on Linux-based
 // systems with epoll API support.
