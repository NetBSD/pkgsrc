$NetBSD: patch-lib_curl__transport_xmlrpc__curl__transport.c,v 1.1 2011/06/30 01:03:26 obache Exp $

* curl/types.h is not used (empty) since curl-7.12.0 and removed at curl-7.21.7.

--- lib/curl_transport/xmlrpc_curl_transport.c.orig	2011-03-25 16:24:55.000000000 +0000
+++ lib/curl_transport/xmlrpc_curl_transport.c
@@ -83,7 +83,6 @@
 #include "xmlrpc-c/time_int.h"
 
 #include <curl/curl.h>
-#include <curl/types.h>
 #include <curl/easy.h>
 #include <curl/multi.h>
 
