$NetBSD: patch-lib_url.c,v 1.2.2.2 2015/01/20 23:58:07 tron Exp $

Apply a fix for CVE-2014-8150: curl failed to handle URLs with embedded
end-of-line characters.

--- lib/url.c.orig	2014-11-05 07:23:42.000000000 +0000
+++ lib/url.c
@@ -3807,6 +3807,13 @@ static CURLcode parseurlandfillconn(stru
 
   *prot_missing = FALSE;
 
+  /* We might pass the entire URL into the request so we need to make sure
+   * there are no bad characters in there.*/
+  if(strpbrk(data->change.url, "\r\n")) {
+    failf(data, "Illegal characters found in URL");
+    return CURLE_URL_MALFORMAT;
+  }
+
   /*************************************************************
    * Parse the URL.
    *
