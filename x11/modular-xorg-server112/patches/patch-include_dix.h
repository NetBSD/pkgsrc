$NetBSD: patch-include_dix.h,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- include/dix.h.orig	2012-05-17 17:09:04.000000000 +0000
+++ include/dix.h
@@ -72,8 +72,13 @@ SOFTWARE.
     if ((sizeof(req) >> 2) > client->req_len )\
          return(BadLength)
 
+#define REQUEST_AT_LEAST_EXTRA_SIZE(req, extra)  \
+    if (((sizeof(req) + ((uint64_t) extra)) >> 2) > client->req_len ) \
+         return(BadLength)
+
 #define REQUEST_FIXED_SIZE(req, n)\
     if (((sizeof(req) >> 2) > client->req_len) || \
+        (((n) >> 2) >= client->req_len) || \
         (((sizeof(req) + (n) + 3) >> 2) != client->req_len)) \
          return(BadLength)
 
