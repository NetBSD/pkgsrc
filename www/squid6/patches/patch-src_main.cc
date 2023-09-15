$NetBSD: patch-src_main.cc,v 1.1 2023/09/15 07:40:05 sborrill Exp $

Workaround linker problem removing ntlm auth
https://github.com/squid-cache/squid/commit/5596a2f4894f80864b660b035d05f5aec74f8312.patch

--- src/main.cc.orig	2023-09-03 07:17:45.000000000 +0100
+++ src/main.cc	2023-09-04 15:26:25.301609039 +0100
@@ -1440,6 +1440,14 @@
 int
 SquidMain(int argc, char **argv)
 {
+    // We must register all modules before the first RunRegisteredHere() call.
+    // We do it ASAP/here so that we do not need to move this code when we add
+    // earlier hooks to the RegisteredRunner API. This collection of
+    // registration calls is not a RegisteredRunner "event" in itself.
+#if HAVE_AUTH_MODULE_NTLM
+    CallRunnerRegistrator(NtlmAuthRr);
+#endif
+
     const CommandLine cmdLine(argc, argv, shortOpStr, squidOptions);
 
     ConfigureCurrentKid(cmdLine);
