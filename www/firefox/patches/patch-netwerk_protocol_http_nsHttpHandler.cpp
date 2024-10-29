$NetBSD: patch-netwerk_protocol_http_nsHttpHandler.cpp,v 1.4 2024/10/29 14:33:40 ryoon Exp $

* Do not freeze user-agent string as Linux under NetBSD.

--- netwerk/protocol/http/nsHttpHandler.cpp.orig	2024-10-18 13:19:10.000000000 +0000
+++ netwerk/protocol/http/nsHttpHandler.cpp
@@ -1048,6 +1048,8 @@ void nsHttpHandler::InitUserAgentCompone
   mOscpu.AssignLiteral("Intel Mac OS X 10.15");
 #elif defined(ANDROID)
   mOscpu.AssignLiteral("Linux armv81");
+#  elif defined(__NetBSD__)
+  mOscpu.AssignLiteral("NetBSD x86_64");
 #else
   mOscpu.AssignLiteral("Linux x86_64");
 #endif
