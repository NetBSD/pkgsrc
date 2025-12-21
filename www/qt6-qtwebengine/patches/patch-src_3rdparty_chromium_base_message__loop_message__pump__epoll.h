$NetBSD: patch-src_3rdparty_chromium_base_message__loop_message__pump__epoll.h,v 1.1 2025/12/21 09:38:14 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/message_loop/message_pump_epoll.h.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/base/message_loop/message_pump_epoll.h
@@ -51,7 +51,11 @@ namespace base {
 // every call, don't do it when we have too many FDs.
 BASE_FEATURE(kUsePollForMessagePumpEpoll,
              "UsePollForMessagePumpEpoll",
+#if BUILDFLAG(IS_BSD)
+             base::FEATURE_ENABLED_BY_DEFAULT);
+#else
              base::FEATURE_DISABLED_BY_DEFAULT);
+#endif
 
 // A MessagePump implementation suitable for I/O message loops on Linux-based
 // systems with epoll API support.
