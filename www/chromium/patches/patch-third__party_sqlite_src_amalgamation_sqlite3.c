$NetBSD: patch-third__party_sqlite_src_amalgamation_sqlite3.c,v 1.14 2026/01/19 16:14:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/sqlite/src/amalgamation/sqlite3.c.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/sqlite/src/amalgamation/sqlite3.c
@@ -14554,7 +14554,7 @@ struct fts5_api {
 ** But _XOPEN_SOURCE define causes problems for Mac OS X, so omit
 ** it.
 */
-#if !defined(_XOPEN_SOURCE) && !defined(__DARWIN__) && !defined(__APPLE__)
+#if !defined(_XOPEN_SOURCE) && !defined(__DARWIN__) && !defined(__APPLE__) && !defined(__FreeBSD__)
 #  define _XOPEN_SOURCE 600
 #endif
 
@@ -21097,6 +21097,9 @@ SQLITE_PRIVATE int sqlite3HeapNearlyFull
 ** The alloca() routine never returns NULL.  This will cause code paths
 ** that deal with sqlite3StackAlloc() failures to be unreachable.
 */
+#if defined(__NetBSD__)
+# undef SQLITE_USE_ALLOCA
+#endif
 #ifdef SQLITE_USE_ALLOCA
 # define sqlite3StackAllocRaw(D,N)   alloca(N)
 # define sqlite3StackAllocRawNN(D,N) alloca(N)
@@ -45647,6 +45650,11 @@ static int unixRandomness(sqlite3_vfs *N
   memset(zBuf, 0, nBuf);
   randomnessPid = osGetpid(0);
 #if !defined(SQLITE_TEST) && !defined(SQLITE_OMIT_RANDOMNESS)
+#if defined(__OpenBSD__)
+  {
+    arc4random_buf(zBuf, nBuf);
+  }
+#else
   {
     int fd, got;
     fd = robust_open("/dev/urandom", O_RDONLY, 0);
@@ -45663,6 +45671,7 @@ static int unixRandomness(sqlite3_vfs *N
     }
   }
 #endif
+#endif
   return nBuf;
 }
 
