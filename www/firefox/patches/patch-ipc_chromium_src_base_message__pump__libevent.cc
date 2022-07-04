$NetBSD: patch-ipc_chromium_src_base_message__pump__libevent.cc,v 1.12 2022/07/04 14:34:08 ryoon Exp $

Allow older libevent

--- ipc/chromium/src/base/message_pump_libevent.cc.orig	2022-06-16 21:32:07.000000000 +0000
+++ ipc/chromium/src/base/message_pump_libevent.cc
@@ -24,6 +24,7 @@
 
 // This macro checks that the _EVENT_SIZEOF_* constants defined in
 // ipc/chromiume/src/third_party/<platform>/event2/event-config.h are correct.
+#if 0
 #if defined(_EVENT_SIZEOF_SHORT)
 #  define CHECK_EVENT_SIZEOF(TYPE, type)                \
     static_assert(_EVENT_SIZEOF_##TYPE == sizeof(type), \
@@ -44,6 +45,7 @@ CHECK_EVENT_SIZEOF(SHORT, short);
 CHECK_EVENT_SIZEOF(SIZE_T, size_t);
 CHECK_EVENT_SIZEOF(TIME_T, time_t);
 CHECK_EVENT_SIZEOF(VOID_P, void*);
+#endif
 
 // Lifecycle of struct event
 // Libevent uses two main data structures:
