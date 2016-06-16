$NetBSD: patch-memory_mozalloc_mozalloc__abort.cpp,v 1.6 2016/06/16 12:08:21 ryoon Exp $

* Support Solaris

--- memory/mozalloc/mozalloc_abort.cpp.orig	2015-08-24 21:53:14.000000000 +0000
+++ memory/mozalloc/mozalloc_abort.cpp
@@ -68,7 +68,11 @@ void fillAbortMessage(char (&msg)[N], ui
 //
 // That segmentation fault will be interpreted as another bug by ASan and as a
 // result, ASan will just exit(1) instead of aborting.
+#if defined(SOLARIS)
+void std::abort(void)
+#else
 void abort(void)
+#endif
 {
 #ifdef MOZ_WIDGET_ANDROID
     char msg[64] = {};
