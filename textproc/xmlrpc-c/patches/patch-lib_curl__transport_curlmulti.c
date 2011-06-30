$NetBSD: patch-lib_curl__transport_curlmulti.c,v 1.1 2011/06/30 01:03:25 obache Exp $

* curl/types.h is not used (empty) since curl-7.12.0 and removed at curl-7.21.7.

--- lib/curl_transport/curlmulti.c.orig	2011-03-25 16:24:54.000000000 +0000
+++ lib/curl_transport/curlmulti.c
@@ -17,7 +17,6 @@
 #endif
 
 #include <curl/curl.h>
-#include <curl/types.h>
 #include <curl/easy.h>
 #include <curl/multi.h>
 
