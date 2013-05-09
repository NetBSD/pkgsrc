$NetBSD: patch-Source_WebCore_platform_network_DNSResolveQueue.h,v 1.1 2013/05/09 14:04:42 joerg Exp $

--- Source/WebCore/platform/network/DNSResolveQueue.h.orig	2013-05-08 08:52:14.000000000 +0000
+++ Source/WebCore/platform/network/DNSResolveQueue.h
@@ -56,7 +56,7 @@ private:
     void fired();
 
     HashSet<String> m_names;
-    int m_requestsInFlight;
+    atomic_int m_requestsInFlight;
 };
 
 }
