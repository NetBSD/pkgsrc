$NetBSD: patch-src_corelib_thread_qyieldcpu.h,v 1.2 2026/04/30 06:38:37 adam Exp $

Xcode 26.4 build fix

--- src/corelib/thread/qyieldcpu.h.orig	2026-03-05 07:51:49.000000000 +0000
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
 #if defined(Q_CC_MSVC_ONLY) && defined(Q_PROCESSOR_X86)
 // MSVC defines _YIELD_PROCESSOR() in <xatomic.h>, but as that is a private
 // header, we include the public ones
