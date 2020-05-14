$NetBSD: patch-iocore_eventsystem_UnixEventProcessor.cc,v 1.1 2020/05/14 18:59:48 joerg Exp $

--- iocore/eventsystem/UnixEventProcessor.cc.orig	2020-05-13 23:41:06.444229785 +0000
+++ iocore/eventsystem/UnixEventProcessor.cc
@@ -32,6 +32,11 @@
 #include "ts/ink_defs.h"
 #include "ts/hugepages.h"
 
+#if defined(__NetBSD__) && !defined(PTHREAD_STACK_MIN)
+#include <machine/vmparam.h>
+#define PTHREAD_STACK_MIN (16 * PAGE_SIZE)
+#endif
+
 EventType
 EventProcessor::spawn_event_threads(int n_threads, const char *et_name, size_t stacksize)
 {
