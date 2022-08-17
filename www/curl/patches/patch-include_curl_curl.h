$NetBSD: patch-include_curl_curl.h,v 1.1 2022/08/17 10:09:55 tnn Exp $

https://github.com/curl/curl/pull/9329

--- include/curl/curl.h.orig	2022-06-23 15:51:43.000000000 +0000
+++ include/curl/curl.h
@@ -75,7 +75,8 @@
     defined(ANDROID) || defined(__ANDROID__) || defined(__OpenBSD__) || \
     defined(__CYGWIN__) || defined(AMIGA) || defined(__NuttX__) || \
    (defined(__FreeBSD_version) && (__FreeBSD_version < 800000)) || \
-   (defined(__MidnightBSD_version) && (__MidnightBSD_version < 100000))
+   (defined(__MidnightBSD_version) && (__MidnightBSD_version < 100000)) || \
+    defined(__sun__)
 #include <sys/select.h>
 #endif
 
