$NetBSD: patch-server_protocol.c,v 1.3.2.1 2012/01/30 03:30:53 sbd Exp $

revision 1179239 from http://svn.apache.org/:
	SECURITY (CVE-2011-3368): Prevent unintended pattern expansion
	in some reverse proxy configurations by strictly validating
	the request-URI.

revision 1179525 from http://svn.apache.org/:
	SECURITY (CVE-2011-3368): Prevent unintended pattern expansion in some
	reverse proxy configurations by strictly validating the request-URI:
	* server/protocol.c (read_request_line): Send a 400 response if the
	  request-URI does not match the grammar from RFC 2616.  This ensures
	  the input string for RewriteRule et al really is an absolute path.

revision 1235454 from http://svn.apache.org/:
	CVE-2012-0053: Fix an issue in error responses that could expose 
	"httpOnly" cookies when no custom ErrorDocument is specified for 
	status code 400.

--- server/protocol.c.orig	2011-05-07 12:39:29.000000000 +0100
+++ server/protocol.c	2012-01-29 12:22:25.000000000 +0000
@@ -640,6 +640,25 @@
 
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
@@ -670,6 +689,16 @@
     return 1;
 }
 
+/* get the length of the field name for logging, but no more than 80 bytes */
+#define LOG_NAME_MAX_LEN 80
+static int field_name_len(const char *field)
+{
+    const char *end = ap_strchr_c(field, ':');
+    if (end == NULL || end - field > LOG_NAME_MAX_LEN)
+        return LOG_NAME_MAX_LEN;
+    return end - field;
+}
+
 AP_DECLARE(void) ap_get_mime_headers_core(request_rec *r, apr_bucket_brigade *bb)
 {
     char *last_field = NULL;
@@ -709,12 +738,15 @@
                 /* insure ap_escape_html will terminate correctly */
                 field[len - 1] = '\0';
                 apr_table_setn(r->notes, "error-notes",
-                               apr_pstrcat(r->pool,
+                               apr_psprintf(r->pool,
                                            "Size of a request header field "
                                            "exceeds server limit.<br />\n"
-                                           "<pre>\n",
-                                           ap_escape_html(r->pool, field),
-                                           "</pre>\n", NULL));
+                                           "<pre>\n%.*s\n</pre>/n",
+                                           field_name_len(field), 
+                                           ap_escape_html(r->pool, field)));
+                ap_log_rerror(APLOG_MARK, APLOG_INFO, 0, r, 
+                              "Request header exceeds LimitRequestFieldSize: "
+                              "%.*s", field_name_len(field), field);
             }
             return;
         }
@@ -735,13 +767,17 @@
                      * overflow (last_field) as the field with the problem
                      */
                     apr_table_setn(r->notes, "error-notes",
-                                   apr_pstrcat(r->pool,
+                                   apr_psprintf(r->pool,
                                                "Size of a request header field "
                                                "after folding "
                                                "exceeds server limit.<br />\n"
-                                               "<pre>\n",
-                                               ap_escape_html(r->pool, last_field),
-                                               "</pre>\n", NULL));
+                                               "<pre>\n%.*s\n</pre>\n",
+                                               field_name_len(last_field),
+                                               ap_escape_html(r->pool, last_field)));
+                    ap_log_rerror(APLOG_MARK, APLOG_INFO, 0, r,
+                                  "Request header exceeds LimitRequestFieldSize "
+                                  "after folding: %.*s",
+                                  field_name_len(last_field), last_field);
                     return;
                 }
 
@@ -773,13 +809,18 @@
                 if (!(value = strchr(last_field, ':'))) { /* Find ':' or    */
                     r->status = HTTP_BAD_REQUEST;      /* abort bad request */
                     apr_table_setn(r->notes, "error-notes",
-                                   apr_pstrcat(r->pool,
+                                   apr_psprintf(r->pool,
                                                "Request header field is "
                                                "missing ':' separator.<br />\n"
-                                               "<pre>\n",
+                                               "<pre>\n%.*s</pre>\n",
+                                               (int)LOG_NAME_MAX_LEN,
                                                ap_escape_html(r->pool,
-                                                              last_field),
-                                               "</pre>\n", NULL));
+                                                              last_field)));
+                    ap_log_rerror(APLOG_MARK, APLOG_DEBUG, 0, r,
+                                  "Request header field is missing ':' "
+                                  "separator: %.*s", (int)LOG_NAME_MAX_LEN,
+                                  last_field);
+
                     return;
                 }
 
