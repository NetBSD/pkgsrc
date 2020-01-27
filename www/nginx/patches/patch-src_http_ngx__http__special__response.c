$NetBSD$

Discard request body when redirecting to a URL via error_page.

Fixes CVE-2019-20372.

https://github.com/nginx/nginx/commit/c1be55f97211d38b69ac0c2027e6812ab8b1b94e.patch

--- src/http/ngx_http_special_response.c
+++ src/http/ngx_http_special_response.c
@@ -623,6 +623,12 @@ ngx_http_send_error_page(ngx_http_request_t *r, ngx_http_err_page_t *err_page)
         return ngx_http_named_location(r, &uri);
     }
 
+    r->expect_tested = 1;
+
+    if (ngx_http_discard_request_body(r) != NGX_OK) {
+        r->keepalive = 0;
+    }
+
     location = ngx_list_push(&r->headers_out.headers);
 
     if (location == NULL) {
