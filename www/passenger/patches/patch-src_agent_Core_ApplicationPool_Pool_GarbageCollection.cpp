$NetBSD: patch-src_agent_Core_ApplicationPool_Pool_GarbageCollection.cpp,v 1.1 2020/03/27 20:51:23 joerg Exp $

--- src/agent/Core/ApplicationPool/Pool/GarbageCollection.cpp.orig	2020-03-27 14:54:52.035140742 +0000
+++ src/agent/Core/ApplicationPool/Pool/GarbageCollection.cpp
@@ -55,7 +55,7 @@ Pool::garbageCollect(PoolPtr self) {
 		self->garbageCollectionCond.timed_wait(lock,
 			posix_time::seconds(5));
 	}
-	while (!this_thread::interruption_requested()) {
+	while (!boost::this_thread::interruption_requested()) {
 		try {
 			UPDATE_TRACE_POINT();
 			unsigned long long sleepTime = self->realGarbageCollect();
