$NetBSD: patch-src_raptor_internal.h,v 1.1 2011/07/02 01:24:28 markd Exp $

curl/types.h is not used (empty) since curl-7.12.0 and removed at curl-7.21.7.

--- src/raptor_internal.h.orig	2010-01-29 23:54:42.000000000 +0000
+++ src/raptor_internal.h
@@ -852,7 +852,6 @@ int raptor_utf8_is_nfc(const unsigned ch
 
 #ifdef RAPTOR_WWW_LIBCURL
 #include <curl/curl.h>
-#include <curl/types.h>
 #include <curl/easy.h>
 #endif
 
