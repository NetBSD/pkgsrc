$NetBSD: patch-autoconf_pecl_libcurl.m4,v 1.1 2021/12/13 15:13:17 taca Exp $

Fix portability.

--- autoconf/pecl/libcurl.m4.orig	2021-09-13 10:46:53.000000000 +0000
+++ autoconf/pecl/libcurl.m4
@@ -181,7 +181,7 @@ AC_DEFUN([PECL_HAVE_LIBCURL_SSL], [dnl
 			fi
 		])
 
-		if test "$PECL_VAR([LIBCURL_SSLLIB])" == "OpenSSL"; then
+		if test "$PECL_VAR([LIBCURL_SSLLIB])" = "OpenSSL"; then
 			PECL_HAVE_CONST([curl/curl.h], [CURLOPT_TLS13_CIPHERS], int, [
 				AC_CACHE_CHECK([whether curl_easy_setopt accepts CURLOPT_TLS13_CIPHERS], PECL_CACHE_VAR([LIBCURL_TLS13_CIPHERS]), [
 					PECL_CACHE_VAR([LIBCURL_TLS13_CIPHERS])=
