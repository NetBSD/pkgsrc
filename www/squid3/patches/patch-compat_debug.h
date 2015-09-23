$NetBSD: patch-compat_debug.h,v 1.1 2015/09/23 03:59:04 taca Exp $

Build fix with IP Filter 4.1.34 (NetBSD 6.1 and may be older).

* Avoid to define debug CPP macro.
* Make the proto typoe of debug() match with IP Filter 4.1.34.

--- compat/debug.h.orig	2015-09-17 13:06:28.000000000 +0000
+++ compat/debug.h
@@ -23,7 +23,7 @@
 SQUIDCEXTERN int debug_enabled;
 
 /* the macro overload style is really a gcc-ism */
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(HAVE_NETINET_IP_FIL_H)
 
 #define debug(X...) \
                      if (debug_enabled) { \
@@ -34,7 +34,7 @@ SQUIDCEXTERN int debug_enabled;
 #else /* __GNUC__ */
 
 /* non-GCC compilers can't do the above macro define yet. */
-void debug(const char *format,...);
+void debug(char *format,...);
 #endif
 
 #endif /* COMPAT_DEBUG_H */
