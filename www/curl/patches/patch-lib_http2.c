$NetBSD: patch-lib_http2.c,v 1.3 2015/06/30 23:00:21 spz Exp $

Update compatibility for nghttp2 1.0. This patch should become obsolete
with curl-7.43.

--- lib/http2.c.orig	2015-04-29 06:06:52.000000000 +0000
+++ lib/http2.c
@@ -1019,8 +1019,8 @@ CURLcode Curl_http2_switched(struct conn
 
   rv = (int) ((Curl_send*)httpc->send_underlying)
     (conn, FIRSTSOCKET,
-     NGHTTP2_CLIENT_CONNECTION_PREFACE,
-     NGHTTP2_CLIENT_CONNECTION_PREFACE_LEN,
+     NGHTTP2_CLIENT_MAGIC,
+     NGHTTP2_CLIENT_MAGIC_LEN,
      &result);
   if(result)
     /* TODO: This may get CURLE_AGAIN */
