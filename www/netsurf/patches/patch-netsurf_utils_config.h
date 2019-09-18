$NetBSD: patch-netsurf_utils_config.h,v 1.2 2019/09/18 20:32:47 nros Exp $

NetBSD has strcasestr(3) and strchrnul(3).

--- netsurf/utils/config.h.orig	2019-07-17 15:37:00.000000000 +0000
+++ netsurf/utils/config.h
@@ -30,7 +30,7 @@
 char *strndup(const char *s, size_t n);
 #endif
 
-#if (defined(_GNU_SOURCE) || defined(__APPLE__) || defined(__HAIKU__) || defined(__OpenBSD__))
+#if (defined(_GNU_SOURCE) || defined(__APPLE__) || defined(__HAIKU__) || defined(__NetBSD__) || defined(__OpenBSD__))
 #define HAVE_STRCASESTR
 #else
 #undef HAVE_STRCASESTR
@@ -51,7 +51,7 @@ char *strcasestr(const char *haystack, c
 /* For some reason, UnixLib defines this unconditionally. Assume we're using
  *  UnixLib if building for RISC OS.
  */
-#if ((defined(_GNU_SOURCE) && !defined(__APPLE__)) || defined(__riscos__))
+#if ((defined(_GNU_SOURCE) && !defined(__APPLE__)) || defined(__riscos__) || defined(__NetBSD__))
 #define HAVE_STRCHRNUL
 #else
 #undef HAVE_STRCHRNUL
