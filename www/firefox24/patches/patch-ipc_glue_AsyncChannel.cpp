$NetBSD: patch-ipc_glue_AsyncChannel.cpp,v 1.1 2013/11/03 04:51:59 ryoon Exp $

--- ipc/glue/AsyncChannel.cpp.orig	2013-05-11 19:19:32.000000000 +0000
+++ ipc/glue/AsyncChannel.cpp
@@ -682,7 +682,7 @@ AsyncChannel::ProcessLink::OnChannelOpen
         mExistingListener = mTransport->set_listener(this);
 #ifdef DEBUG
         if (mExistingListener) {
-            queue<Message> pending;
+            std::queue<Message> pending;
             mExistingListener->GetQueuedMessages(pending);
             MOZ_ASSERT(pending.empty());
         }
@@ -699,7 +699,7 @@ AsyncChannel::ProcessLink::OnTakeConnect
 {
     AssertIOThread();
 
-    queue<Message> pending;
+    std::queue<Message> pending;
     {
         MonitorAutoLock lock(*mChan->mMonitor);
 
