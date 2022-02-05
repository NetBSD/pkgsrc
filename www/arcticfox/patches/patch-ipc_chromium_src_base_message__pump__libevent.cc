$NetBSD: patch-ipc_chromium_src_base_message__pump__libevent.cc,v 1.1 2022/02/05 20:51:07 nia Exp $

Avoid compilation failure caused by slightly-incompatible libevent
headers.

--- ipc/chromium/src/base/message_pump_libevent.cc.orig	2021-12-03 05:22:04.000000000 +0000
+++ ipc/chromium/src/base/message_pump_libevent.cc
@@ -22,19 +22,6 @@
 #include "third_party/libevent/event.h"
 #include "mozilla/UniquePtr.h"
 
-// This macro checks that the _EVENT_SIZEOF_* constants defined in
-// ipc/chromiume/src/third_party/<platform>/event2/event-config.h are correct.
-#define CHECK_EVENT_SIZEOF(TYPE, type) \
-    static_assert(_EVENT_SIZEOF_##TYPE == sizeof(type), \
-    "bad _EVENT_SIZEOF_"#TYPE);
-
-CHECK_EVENT_SIZEOF(LONG,      long);
-CHECK_EVENT_SIZEOF(LONG_LONG, long long);
-CHECK_EVENT_SIZEOF(PTHREAD_T, pthread_t);
-CHECK_EVENT_SIZEOF(SHORT,     short);
-CHECK_EVENT_SIZEOF(SIZE_T,    size_t);
-CHECK_EVENT_SIZEOF(VOID_P,    void*);
-
 // Lifecycle of struct event
 // Libevent uses two main data structures:
 // struct event_base (of which there is one per message pump), and
