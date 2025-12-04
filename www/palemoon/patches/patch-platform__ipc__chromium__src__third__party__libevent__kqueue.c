--- platform/ipc/chromium/src/third_party/libevent/kqueue.c.orig	2025-10-15 19:46:52.000000000 +0200
+++ platform/ipc/chromium/src/third_party/libevent/kqueue.c	2025-12-03 16:26:33.558111547 +0100
@@ -49,7 +49,7 @@
 /* Some platforms apparently define the udata field of struct kevent as
  * intptr_t, whereas others define it as void*.  There doesn't seem to be an
  * easy way to tell them apart via autoconf, so we need to use OS macros. */
-#if defined(_EVENT_HAVE_INTTYPES_H) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__darwin__) && !defined(__APPLE__)
+#if defined(_EVENT_HAVE_INTTYPES_H) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__darwin__) && !defined(__APPLE__)
 #define PTR_TO_UDATA(x)	((intptr_t)(x))
 #define INT_TO_UDATA(x) ((intptr_t)(x))
 #else
