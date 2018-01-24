$NetBSD: patch-ipc_glue_MessageChannel.cpp,v 1.1 2018/01/24 16:52:08 ryoon Exp $

--- ipc/glue/MessageChannel.cpp.orig	2018-01-11 20:17:05.000000000 +0000
+++ ipc/glue/MessageChannel.cpp
@@ -686,6 +686,11 @@ MessageChannel::WillDestroyCurrentMessag
     mWorkerLoop = nullptr;
 }
 
+#if defined(_LIBCPP_VERSION) && _LIBCPP_VERSION < 4000
+// Work around UB in __tree crashing mPendingPromises.clear()
+// http://llvm.org/viewvc/llvm-project?view=revision&revision=276003
+[[clang::optnone]]
+#endif
 void
 MessageChannel::Clear()
 {
