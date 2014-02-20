$NetBSD: patch-memory_mozalloc_mozalloc__abort.cpp,v 1.3 2014/02/20 13:19:03 ryoon Exp $

--- memory/mozalloc/mozalloc_abort.cpp.orig	2013-05-11 19:19:46.000000000 +0000
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
