$NetBSD: patch-src_main.c,v 1.3 2025/08/29 12:17:31 leot Exp $

- Fix ctype(3) abuses
- DragonFly also has a particular 'cpuset' type

--- src/main.c.orig	2018-08-07 06:20:25.000000000 +0000
+++ src/main.c
@@ -117,7 +117,7 @@ int main(int argc, char **argv) {
             /* Search routine needs the query to be lowercase */
             char *c = opts.query;
             for (; *c != '\0'; ++c) {
-                *c = (char)tolower(*c);
+                *c = (char)tolower((unsigned char)*c);
             }
         }
         generate_alpha_skip(opts.query, opts.query_len, alpha_skip_lookup, opts.casing == CASE_SENSITIVE);
@@ -156,7 +156,7 @@ int main(int argc, char **argv) {
             if (opts.use_thread_affinity) {
 #ifdef __linux__
                 cpu_set_t cpu_set;
-#elif __FreeBSD__
+#elif __FreeBSD__ || __DragonFly__
                 cpuset_t cpu_set;
 #endif
                 CPU_ZERO(&cpu_set);
