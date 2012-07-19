$NetBSD: patch-mozilla_netwerk_protocol_http_HttpChannelParent.cpp,v 1.3 2012/07/19 17:33:29 ryoon Exp $

* Fix build with gcc<4.5, for example, DragonFly 3.0.1.
  See https://bugzilla.mozilla.org/show_bug.cgi?id=621446

--- mozilla/netwerk/protocol/http/HttpChannelParent.cpp.orig	2012-07-17 18:35:20.000000000 +0000
+++ mozilla/netwerk/protocol/http/HttpChannelParent.cpp
@@ -340,6 +340,10 @@ HttpChannelParent::RecvUpdateAssociatedC
 // Compiling this with GCC <= 4.4 fails with an internal compiler error
 #pragma GCC optimize ("O0")
 #endif
+#if !defined(__GNUC__) || \
+  (__GNUC__ >= 5) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 5)
+#pragma GCC optimize ("O0")
+#endif
 
 bool
 HttpChannelParent::RecvRedirect2Verify(const nsresult& result, 
