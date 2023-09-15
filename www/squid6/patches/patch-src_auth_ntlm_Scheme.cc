$NetBSD: patch-src_auth_ntlm_Scheme.cc,v 1.1 2023/09/15 07:40:05 sborrill Exp $

Workaround linker problem removing ntlm auth
https://github.com/squid-cache/squid/commit/5596a2f4894f80864b660b035d05f5aec74f8312.patch

--- src/auth/ntlm/Scheme.cc.orig	2023-09-03 07:17:45.000000000 +0100
+++ src/auth/ntlm/Scheme.cc	2023-09-04 15:26:25.285516743 +0100
@@ -23,7 +23,8 @@
         debugs(29, 2, "Initialized Authentication Scheme '" << type << "'");
     }
 };
-RunnerRegistrationEntry(NtlmAuthRr);
+
+DefineRunnerRegistrator(NtlmAuthRr);
 
 Auth::Scheme::Pointer
 Auth::Ntlm::Scheme::GetInstance()
