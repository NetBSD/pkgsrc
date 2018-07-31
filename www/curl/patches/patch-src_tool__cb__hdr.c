$NetBSD: patch-src_tool__cb__hdr.c,v 1.1 2018/07/31 09:34:49 wiz Exp $

curl: use Content-Disposition before the "URL end" for -OJ

Regression introduced in 7.61.0

https://github.com/curl/curl/commit/e78f2cfe56c39a6c32191c207aae683de0e9a042

--- src/tool_cb_hdr.c.orig	2018-07-09 06:42:12.000000000 +0000
+++ src/tool_cb_hdr.c
@@ -103,9 +103,6 @@ size_t tool_header_cb(char *ptr, size_t 
      (protocol & (CURLPROTO_HTTPS|CURLPROTO_HTTP))) {
     const char *p = str + 20;
 
-    if(!outs->stream && !tool_create_output_file(outs, FALSE))
-      return failure;
-
     /* look for the 'filename=' parameter
        (encoded filenames (*=) are not supported) */
     for(;;) {
@@ -153,6 +150,8 @@ size_t tool_header_cb(char *ptr, size_t 
       }
       break;
     }
+    if(!outs->stream && !tool_create_output_file(outs, FALSE))
+      return failure;
   }
 
   if(hdrcbdata->config->show_headers &&
