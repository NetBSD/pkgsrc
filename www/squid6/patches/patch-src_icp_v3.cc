$NetBSD: patch-src_icp_v3.cc,v 1.1 2026/03/25 11:47:46 sborrill Exp $

Backport fixes for:
SQUID-2026:2 Denial of Service in ICP Request handling (CVE-2026-32748)
SQUID-2026:3 Out of Bounds Read in ICP message handling (CVE-2026-33515)

https://github.com/squid-cache/squid/commit/703e07d25ca6fa11f52d20bf0bb879e22ab7481b
https://github.com/squid-cache/squid/commit/8138e909d2058d4401e0ad49b583afaec912b165

--- src/icp_v3.cc.orig	2025-06-24 08:49:30.000000000 +0100
+++ src/icp_v3.cc	2026-03-25 09:25:04.012952882 +0000
@@ -32,23 +32,21 @@
 
 /// \ingroup ServerProtocolICPInternal3
 static void
-doV3Query(int fd, Ip::Address &from, char *buf, icp_common_t header)
+doV3Query(int fd, Ip::Address &from, const char * const buf, icp_common_t header)
 {
-    /* We have a valid packet */
-    char *url = buf + sizeof(icp_common_t) + sizeof(uint32_t);
-    HttpRequest *icp_request = icpGetRequest(url, header.reqnum, fd, from);
-
-    if (!icp_request)
+    const auto url = icpGetUrl(from, buf, header);
+    if (!url) {
+        icpCreateAndSend(ICP_ERR, 0, "", header.reqnum, 0, fd, from, nullptr);
         return;
+    }
 
-    if (!icpAccessAllowed(from, icp_request)) {
-        icpDenyAccess (from, url, header.reqnum, fd);
-        delete icp_request;
+    const auto icp_request = icpGetRequest(url, header.reqnum, fd, from);
+
+    if (!icp_request)
         return;
-    }
 
     /* The peer is allowed to use this cache */
-    ICP3State state(header, icp_request);
+    ICP3State state(header, icp_request.getRaw());
     state.fd = fd;
     state.from = from;
     state.url = xstrdup(url);
