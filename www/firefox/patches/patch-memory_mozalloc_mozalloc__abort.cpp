$NetBSD: patch-memory_mozalloc_mozalloc__abort.cpp,v 1.2 2014/02/08 09:36:00 ryoon Exp $

--- memory/mozalloc/mozalloc_abort.cpp.orig	2014-01-28 04:03:59.000000000 +0000
+++ memory/mozalloc/mozalloc_abort.cpp
@@ -34,7 +34,11 @@ mozalloc_abort(const char* const msg)
 // Define abort() here, so that it is used instead of the system abort(). This
 // lets us control the behavior when aborting, in order to get better results
 // on *NIX platforms. See mozalloc_abort for details.
+#if defined(SOLARIS)
+void std::abort(void)
+#else
 void abort(void)
+#endif
 {
     mozalloc_abort("Redirecting call to abort() to mozalloc_abort\n");
 }
