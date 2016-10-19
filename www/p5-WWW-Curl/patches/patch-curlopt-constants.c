$NetBSD: patch-curlopt-constants.c,v 1.1 2016/10/19 22:51:11 wiz Exp $

Remove constant that's gone from curl.

--- curlopt-constants.c.orig	2016-10-19 22:49:23.401619025 +0000
+++ curlopt-constants.c
@@ -123,7 +123,6 @@ constant(const char *name)
             if (strEQ(name, "SSLVERSION_TLSv1_0")) return CURL_SSLVERSION_TLSv1_0;
             if (strEQ(name, "SSLVERSION_TLSv1_1")) return CURL_SSLVERSION_TLSv1_1;
             if (strEQ(name, "SSLVERSION_TLSv1_2")) return CURL_SSLVERSION_TLSv1_2;
-            if (strEQ(name, "STRICTER")) return CURL_STRICTER;
             break;
         case 'T':
             if (strEQ(name, "TIMECOND_IFMODSINCE")) return CURL_TIMECOND_IFMODSINCE;
