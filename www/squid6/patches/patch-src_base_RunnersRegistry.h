$NetBSD: patch-src_base_RunnersRegistry.h,v 1.1 2023/09/15 07:40:05 sborrill Exp $

Workaround linker problem removing ntlm auth
https://github.com/squid-cache/squid/commit/5596a2f4894f80864b660b035d05f5aec74f8312.patch

--- src/base/RunnersRegistry.h.orig	2023-09-03 07:17:45.000000000 +0100
+++ src/base/RunnersRegistry.h	2023-09-04 15:26:25.292793976 +0100
@@ -121,11 +121,34 @@
 /// convenience function to "use" an otherwise unreferenced static variable
 bool UseThisStatic(const void *);
 
+// TODO: Remove, together with UseThisStatic(), after migrating to DefineRunnerRegistrator()
 /// convenience macro: register one RegisteredRunner kid as early as possible
 #define RunnerRegistrationEntry(Who) \
     static const bool Who ## _Registered_ = \
         RegisterRunner(new Who) > 0 && \
         UseThisStatic(& Who ## _Registered_);
 
+/// helps DefineRunnerRegistrator() and CallRunnerRegistrator() to use the same
+/// registration function name
+#define DeclareRunnerRegistrator(Who) \
+    void Register ## Who ## Now()
+
+/// Define registration code for the given RegisteredRunner class. A matching
+/// CallRunnerRegistrator(Who) call should run this code before any possible use
+/// of the being-registered module.
+#define DefineRunnerRegistrator(Who) \
+    DeclareRunnerRegistrator(Who); \
+    void Register ## Who ## Now() { \
+        const auto registered = RegisterRunner(new Who); \
+        assert(registered); \
+    }
+
+/// convenience macro: register one RegisteredRunner kid
+#define CallRunnerRegistrator(Who) \
+    do { \
+        DeclareRunnerRegistrator(Who); \
+        Register ## Who ## Now(); \
+    } while (false)
+
 #endif /* SQUID_BASE_RUNNERSREGISTRY_H */
 
