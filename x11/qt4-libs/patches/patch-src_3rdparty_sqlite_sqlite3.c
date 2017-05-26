$NetBSD: patch-src_3rdparty_sqlite_sqlite3.c,v 1.1 2017/05/26 12:09:11 jperkin Exp $

Only define _XOPEN_SOURCE on SunOS if not already using C99 or above.

--- src/3rdparty/sqlite/sqlite3.c.orig	2015-05-07 14:14:48.000000000 +0000
+++ src/3rdparty/sqlite/sqlite3.c
@@ -424,7 +424,7 @@
 **
 ** See also ticket #2741.
 */
-#if !defined(_XOPEN_SOURCE) && !defined(__DARWIN__) && !defined(__APPLE__) && SQLITE_THREADSAFE && !defined(VXWORKS)
+#if !defined(_XOPEN_SOURCE) && !defined(__DARWIN__) && !defined(__APPLE__) && SQLITE_THREADSAFE && !defined(VXWORKS) && (!defined(__sun) || __STDC_VERSION__ - 0 < 199901L)
 #  define _XOPEN_SOURCE 500  /* Needed to enable pthread recursive mutexes */
 #endif
 
