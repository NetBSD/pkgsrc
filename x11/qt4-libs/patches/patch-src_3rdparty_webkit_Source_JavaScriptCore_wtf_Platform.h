$NetBSD: patch-src_3rdparty_webkit_Source_JavaScriptCore_wtf_Platform.h,v 1.1 2016/08/30 07:58:27 richard Exp $
deal with aarch64
--- src/3rdparty/webkit/Source/JavaScriptCore/wtf/Platform.h.orig	2015-05-07 14:14:45.000000000 +0000
+++ src/3rdparty/webkit/Source/JavaScriptCore/wtf/Platform.h
@@ -373,6 +373,10 @@
 #define WTF_CPU_NEEDS_ALIGNED_ACCESS 1
 #endif
 
+/* CPU(AARCH64) */
+#if defined(__aarch64__)
+#define WTF_CPU_AARCH64 1
+#endif
 /* ==== OS() - underlying operating system; only to be used for mandated low-level services like 
    virtual memory, not to choose a GUI toolkit ==== */
 
@@ -1003,7 +1007,8 @@
     || CPU(SPARC64) \
     || CPU(S390X) \
     || CPU(PPC64) \
-    || CPU(MIPS64)
+    || CPU(MIPS64) \
+    || CPU(AARCH64)
 #define WTF_USE_JSVALUE64 1
 #else
 #define WTF_USE_JSVALUE32_64 1
