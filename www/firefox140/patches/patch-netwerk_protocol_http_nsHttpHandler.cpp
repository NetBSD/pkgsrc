$NetBSD: patch-netwerk_protocol_http_nsHttpHandler.cpp,v 1.1 2025/10/19 11:56:56 leot Exp $

* Do not freeze user-agent string as Linux under NetBSD.

--- netwerk/protocol/http/nsHttpHandler.cpp.orig	2024-12-26 14:27:48.719857849 +0000
+++ netwerk/protocol/http/nsHttpHandler.cpp
@@ -1063,6 +1063,8 @@ void nsHttpHandler::InitUserAgentCompone
   mOscpu.AssignLiteral("Linux armv81");
 #elif defined(XP_IOS)
   mOscpu.AssignLiteral("iPhone");
+#elif defined(__NetBSD__)
+  mOscpu.AssignLiteral("NetBSD x86_64");
 #else
   mOscpu.AssignLiteral("Linux x86_64");
 #endif
