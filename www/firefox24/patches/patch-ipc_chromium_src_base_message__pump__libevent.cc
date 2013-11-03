$NetBSD: patch-ipc_chromium_src_base_message__pump__libevent.cc,v 1.1 2013/11/03 04:51:59 ryoon Exp $

--- ipc/chromium/src/base/message_pump_libevent.cc.orig	2013-05-11 19:19:32.000000000 +0000
+++ ipc/chromium/src/base/message_pump_libevent.cc
@@ -16,7 +16,7 @@
 #include "base/scoped_ptr.h"
 #include "base/time.h"
 #include "nsDependentSubstring.h"
-#include "third_party/libevent/event.h"
+#include "event.h"
 
 // Lifecycle of struct event
 // Libevent uses two main data structures:
