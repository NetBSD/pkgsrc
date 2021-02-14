$NetBSD: patch-src_nxt__unix.h,v 1.1 2021/02/14 11:56:57 otis Exp $

Move _XOPEN_SOURCE to CFLAGS

--- src/nxt_unix.h.orig	2020-11-19 18:12:30.000000000 +0000
+++ src/nxt_unix.h
@@ -71,23 +71,6 @@
 #define _POSIX_PTHREAD_SEMANTICS    /* 2 arguments in sigwait(). */
 #endif
 
-/*
- * Solaris provides two sockets API:
- *
- * 1) 4.3BSD sockets (int instead of socklen_t in accept(), etc.;
- *    struct msghdr.msg_accrights) in libsocket;
- * 2) X/Open sockets (socklen_t, struct msghdr.msg_control) with __xnet_
- *    function name prefix in libxnet and libsocket.
- */
-
-/* Enable X/Open sockets API. */
-#define _XOPEN_SOURCE
-#define _XOPEN_SOURCE_EXTENDED  1
-/* Enable Solaris extensions disabled by _XOPEN_SOURCE. */
-#ifndef __EXTENSIONS__
-#define __EXTENSIONS__
-#endif
-
 #endif /* NXT_SOLARIS */
 
 
