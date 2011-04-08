$NetBSD: patch-utils.c,v 1.1 2011/04/08 12:26:29 adam Exp $

Clang does not handle inlines across source files.

--- utils.c.orig	2011-04-08 11:09:48.000000000 +0000
+++ utils.c
@@ -726,7 +726,10 @@ void uwsgi_log_verbose(const char *fmt, 
 	rlen = write(2, logpkt, rlen);
 }
 
-inline int uwsgi_strncmp(char *src, int slen, char *dst, int dlen) {
+#ifndef __clang__
+inline
+#endif
+int uwsgi_strncmp(char *src, int slen, char *dst, int dlen) {
 
 	if (slen != dlen) return 1;
 
@@ -734,14 +737,20 @@ inline int uwsgi_strncmp(char *src, int 
 
 }
 
-inline int uwsgi_starts_with(char *src, int slen, char *dst, int dlen) {
+#ifndef __clang__
+inline
+#endif
+int uwsgi_starts_with(char *src, int slen, char *dst, int dlen) {
 
 	if (slen < dlen) return -1;
 
 	return memcmp(src, dst, dlen);
 }
 
-inline int uwsgi_startswith(char *src, char *what, int wlen) {
+#ifndef __clang__
+inline
+#endif
+int uwsgi_startswith(char *src, char *what, int wlen) {
 
 	int i;
 
@@ -1263,7 +1272,10 @@ int uwsgi_waitfd(int fd, int timeout) {
 }
 
 
-inline void *uwsgi_malloc(size_t size) {
+#ifndef __clang__
+inline
+#endif
+void *uwsgi_malloc(size_t size) {
 
 	char *ptr = malloc(size);
 	if (ptr == NULL) {
