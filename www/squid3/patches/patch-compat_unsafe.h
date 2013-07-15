$NetBSD: patch-compat_unsafe.h,v 1.1 2013/07/15 17:56:45 joerg Exp $

Disable macros that break libc++'s cstdio.

--- compat/unsafe.h.orig	2013-07-14 20:04:32.000000000 +0000
+++ compat/unsafe.h
@@ -6,12 +6,14 @@
  */
 
 #if !SQUID_NO_STRING_BUFFER_PROTECT
+#if 0
 #ifndef sprintf
 #define sprintf ERROR_sprintf_UNSAFE_IN_SQUID
 #endif
 #ifndef strdup
 #define strdup ERROR_strdup_UNSAFE_IN_SQUID
 #endif
+#endif
 #endif /* SQUID_NO_STRING_BUFFER_PROTECT */
 
 #endif /* _SQUID_COMPAT_UNSAFE_H */
