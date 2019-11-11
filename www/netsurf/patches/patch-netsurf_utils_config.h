$NetBSD: patch-netsurf_utils_config.h,v 1.3 2019/11/11 12:31:16 nros Exp $

NetBSD has strcasestr(3)
NetBSD 8 and later has strchrnul(3).

--- netsurf/utils/config.h.orig	2019-07-17 15:37:00.000000000 +0000
+++ netsurf/utils/config.h
@@ -21,6 +21,10 @@
 
 #include <stddef.h>
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
+
 /* Try to detect which features the target OS supports */
 
 #if (defined(_GNU_SOURCE) && !defined(__APPLE__) || defined(__amigaos4__) || defined(__HAIKU__) || (defined(_POSIX_C_SOURCE) && ((_POSIX_C_SOURCE - 0) >= 200809L)) && !defined(__riscos__))
@@ -30,7 +34,7 @@
 char *strndup(const char *s, size_t n);
 #endif
 
-#if (defined(_GNU_SOURCE) || defined(__APPLE__) || defined(__HAIKU__) || defined(__OpenBSD__))
+#if (defined(_GNU_SOURCE) || defined(__APPLE__) || defined(__HAIKU__) || defined(__NetBSD__) || defined(__OpenBSD__))
 #define HAVE_STRCASESTR
 #else
 #undef HAVE_STRCASESTR
@@ -51,7 +55,7 @@ char *strcasestr(const char *haystack, c
 /* For some reason, UnixLib defines this unconditionally. Assume we're using
  *  UnixLib if building for RISC OS.
  */
-#if ((defined(_GNU_SOURCE) && !defined(__APPLE__)) || defined(__riscos__))
+#if ((defined(_GNU_SOURCE) && !defined(__APPLE__)) || defined(__riscos__) || (defined(__NetBSD_Version__) && __NetBSD_Prereq__(8,0,0)))
 #define HAVE_STRCHRNUL
 #else
 #undef HAVE_STRCHRNUL
