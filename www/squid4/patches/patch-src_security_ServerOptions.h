$NetBSD: patch-src_security_ServerOptions.h,v 1.1 2020/01/10 21:22:22 joerg Exp $

--- src/security/ServerOptions.h.orig	2020-01-09 22:33:01.407843695 +0000
+++ src/security/ServerOptions.h
@@ -35,7 +35,6 @@ public:
         // is more secure to have only a small set of trusted CA.
         flags.tlsDefaultCa.defaultTo(false);
     }
-    ServerOptions(const ServerOptions &) = default;
     ServerOptions &operator =(const ServerOptions &);
     ServerOptions(ServerOptions &&o) { this->operator =(o); }
     ServerOptions &operator =(ServerOptions &&o) { this->operator =(o); return *this; }
