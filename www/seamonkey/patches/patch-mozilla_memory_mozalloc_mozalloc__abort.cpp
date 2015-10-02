$NetBSD: patch-mozilla_memory_mozalloc_mozalloc__abort.cpp,v 1.3 2015/10/02 22:49:36 ryoon Exp $

--- mozilla/memory/mozalloc/mozalloc_abort.cpp.orig	2015-09-25 07:35:44.000000000 +0000
+++ mozilla/memory/mozalloc/mozalloc_abort.cpp
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
