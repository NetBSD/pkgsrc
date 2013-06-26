$NetBSD: patch-js__public__HeapAPI.h,v 1.2 2013/06/26 11:32:12 ryoon Exp $

From bugzilla, bug 840242,
https://hg.mozilla.org/integration/mozilla-inbound/rev/49e4ff129351
Use the runtime page size to control arena decommit.

As a side effect, this removes the hard coded page-size == 4k requirement.


+++ js/public/HeapAPI.h
--- js/public/HeapAPI.h.orig	2013-05-11 21:19:32.000000000 +0200
+++ js/public/HeapAPI.h	2013-06-09 21:27:12.000000000 +0200
@@ -11,24 +11,7 @@
 namespace js {
 namespace gc {
 
-/*
- * Page size must be static to support our arena pointer optimizations, so we
- * are forced to support each platform with non-4096 pages as a special case.
- * Note: The freelist supports a maximum arena shift of 15.
- * Note: Do not use JS_CPU_SPARC here, this header is used outside JS.
- */
-#if (defined(SOLARIS) || defined(__FreeBSD__)) && \
-    (defined(__sparc) || defined(__sparcv9) || defined(__ia64))
-const size_t PageShift = 13;
-const size_t ArenaShift = PageShift;
-#elif defined(__powerpc64__)
-const size_t PageShift = 16;
 const size_t ArenaShift = 12;
-#else
-const size_t PageShift = 12;
-const size_t ArenaShift = PageShift;
-#endif
-const size_t PageSize = size_t(1) << PageShift;
 const size_t ArenaSize = size_t(1) << ArenaShift;
 const size_t ArenaMask = ArenaSize - 1;
 
