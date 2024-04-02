$NetBSD: patch-src_main.c,v 1.2 2024/04/02 01:28:00 charlotte Exp $

DragonFly also has a particular 'cpuset' type.

--- src/main.c.orig	2022-05-23 22:57:49.749747000 -0700
+++ src/main.c	2022-05-23 22:58:26.439723000 -0700
@@ -156,7 +156,7 @@
             if (opts.use_thread_affinity) {
 #ifdef __linux__
                 cpu_set_t cpu_set;
-#elif __FreeBSD__
+#elif __FreeBSD__ || __DragonFly__
                 cpuset_t cpu_set;
 #endif
                 CPU_ZERO(&cpu_set);
