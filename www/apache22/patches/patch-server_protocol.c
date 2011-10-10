$NetBSD: patch-server_protocol.c,v 1.1 2011/10/10 10:13:42 taca Exp $

revision 1179239 from http://svn.apache.org/:
	SECURITY (CVE-2011-3368): Prevent unintended pattern expansion
	in some reverse proxy configurations by strictly validating
	the request-URI.

--- server/protocol.c.orig	2011-10-10 09:11:16.000000000 +0000
+++ server/protocol.c
@@ -640,6 +640,25 @@ static int read_request_line(request_rec
 
     ap_parse_uri(r, uri);
 
+    /* RFC 2616:
+     *   Request-URI    = "*" | absoluteURI | abs_path | authority
+     *
+     * authority is a special case for CONNECT.  If the request is not
+     * using CONNECT, and the parsed URI does not have scheme, and
+     * it does not begin with '/', and it is not '*', then, fail
+     * and give a 400 response. */
+    if (r->method_number != M_CONNECT
+	&& !r->parsed_uri.scheme 
+	&& uri[0] != '/'
+	&& !(uri[0] == '*' && uri[1] == '\0')) {
+	    ap_log_rerror(APLOG_MARK, APLOG_ERR, 0, r,
+			  "invalid request-URI %s", uri);
+	    r->args = NULL;
+	    r->hostname = NULL;
+	    r->status = HTTP_BAD_REQUEST;
+	    r->uri = apr_pstrdup(r->pool, uri);
+    }
+
     if (ll[0]) {
         r->assbackwards = 0;
         pro = ll;
