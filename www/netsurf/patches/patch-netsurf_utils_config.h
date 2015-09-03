$NetBSD: patch-netsurf_utils_config.h,v 1.1 2015/09/03 20:56:10 leot Exp $

NetBSD has strcasestr(3).

--- netsurf/utils/config.h.orig	2015-03-11 07:34:53.000000000 +0000
+++ netsurf/utils/config.h
@@ -31,7 +31,7 @@
 char *strndup(const char *s, size_t n);
 #endif
 
-#if (defined(_GNU_SOURCE) || defined(__APPLE__) || defined(__HAIKU__) || defined(__OpenBSD__))
+#if (defined(_GNU_SOURCE) || defined(__APPLE__) || defined(__HAIKU__) || defined(__NetBSD__) || defined(__OpenBSD__))
 #define HAVE_STRCASESTR
 #else
 #undef HAVE_STRCASESTR
