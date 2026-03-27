$NetBSD: patch-src_corelib_thread_qyieldcpu.h,v 1.1 2026/03/27 17:24:05 tnn Exp $

Xcode 26.4 build fix

--- src/corelib/thread/qyieldcpu.h.orig	2026-01-13 10:18:17.000000000 +0000
+++ src/corelib/thread/qyieldcpu.h
@@ -10,6 +10,12 @@
 #include <QtCore/qprocessordetection.h>
 #include <QtCore/qtconfigmacros.h>
 
+#if defined(__APPLE__) && defined(__aarch64__)
+#  if __has_include(<arm_acle.h>)
+#    include <arm_acle.h> /* for __yield() */
+#  endif
+#endif
+
 #ifdef Q_CC_MSVC_ONLY
 // MSVC defines _YIELD_PROCESSOR() in <xatomic.h>, but as that is a private
 // header, we include the public ones
