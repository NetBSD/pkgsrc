$NetBSD: patch-Source_WTF_wtf_Compiler.h,v 1.3 2016/06/16 20:42:36 leot Exp $

Revert upstream changeset 188912, requested in:

 <https://bugs.webkit.org/show_bug.cgi?id=148430>

XXX: Actually in pkgsrc we are using a kludge in order to avoid a pretty new gcc
XXX: version, that in reality is needed only for IndexedDB support (disabled in
XXX: the pkgsrc case).

--- Source/WTF/wtf/Compiler.h.orig	2016-04-11 06:18:43.000000000 +0000
+++ Source/WTF/wtf/Compiler.h
@@ -70,15 +70,17 @@
 #define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
 #define GCC_VERSION_AT_LEAST(major, minor, patch) (GCC_VERSION >= (major * 10000 + minor * 100 + patch))
 
-#if !GCC_VERSION_AT_LEAST(4, 9, 0)
-#error "Please use a newer version of GCC. WebKit requires GCC 4.9.0 or newer to compile."
+#if !GCC_VERSION_AT_LEAST(4, 7, 0)
+#error "Please use a newer version of GCC. WebKit requires GCC 4.7.0 or newer to compile."
 #endif
 
 #if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
 #define WTF_COMPILER_SUPPORTS_C_STATIC_ASSERT 1
 #endif
 
+#if GCC_VERSION_AT_LEAST(4, 8, 0)
 #pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
+#endif
 
 #endif /* COMPILER(GCC) */
 
