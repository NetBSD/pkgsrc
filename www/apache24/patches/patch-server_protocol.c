$NetBSD: patch-server_protocol.c,v 1.1 2015/06/11 15:38:48 taca Exp $

Fix for CVE-2015-0253, introduced in Apache 2.4.11.

--- server/protocol.c.orig	2014-11-29 09:22:43.000000000 +0000
+++ server/protocol.c
@@ -599,8 +599,6 @@ static int read_request_line(request_rec
              */
             if (APR_STATUS_IS_ENOSPC(rv)) {
                 r->status    = HTTP_REQUEST_URI_TOO_LARGE;
-                r->proto_num = HTTP_VERSION(1,0);
-                r->protocol  = apr_pstrdup(r->pool, "HTTP/1.0");
             }
             else if (APR_STATUS_IS_TIMEUP(rv)) {
                 r->status = HTTP_REQUEST_TIME_OUT;
@@ -608,6 +606,8 @@ static int read_request_line(request_rec
             else if (APR_STATUS_IS_EINVAL(rv)) {
                 r->status = HTTP_BAD_REQUEST;
             }
+	    r->proto_num = HTTP_VERSION(1,0);
+	    r->protocol  = apr_pstrdup(r->pool, "HTTP/1.0");
             return 0;
         }
     } while ((len <= 0) && (++num_blank_lines < max_blank_lines));
