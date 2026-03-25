$NetBSD: patch-src_icp_v2.cc,v 1.1 2026/03/25 11:47:46 sborrill Exp $

Backport fixes for:
SQUID-2026:1 Denial of Service in ICP Request handling (CVE-2026-33526)
SQUID-2026:2 Denial of Service in ICP Request handling (CVE-2026-32748)
SQUID-2026:3 Out of Bounds Read in ICP message handling (CVE-2026-33515)

https://github.com/squid-cache/squid/commit/8a7d42f9d44befb8fcbbb619505587c8de6a1e91
https://github.com/squid-cache/squid/commit/703e07d25ca6fa11f52d20bf0bb879e22ab7481b
https://github.com/squid-cache/squid/commit/8138e909d2058d4401e0ad49b583afaec912b165

--- src/icp_v2.cc.orig	2025-06-24 08:49:30.000000000 +0100
+++ src/icp_v2.cc	2026-03-25 09:23:17.804536734 +0000
@@ -425,7 +425,7 @@
 }
 
 void
-icpDenyAccess(Ip::Address &from, char *url, int reqnum, int fd)
+icpDenyAccess(const Ip::Address &from, const char *url, const int reqnum, const int fd)
 {
     debugs(12, 2, "icpDenyAccess: Access Denied for " << from << " by " << AclMatchedName << ".");
 
@@ -440,8 +440,9 @@
     }
 }
 
-bool
-icpAccessAllowed(Ip::Address &from, HttpRequest * icp_request)
+/// icpGetRequest() helper that determines whether squid.conf allows the given ICP query
+static bool
+icpAccessAllowed(const Ip::Address &from, HttpRequest * icp_request)
 {
     /* absent any explicit rules, we deny all */
     if (!Config.accessList.icp)
@@ -453,44 +454,79 @@
     return checklist.fastCheck().allowed();
 }
 
-HttpRequest *
-icpGetRequest(char *url, int reqnum, int fd, Ip::Address &from)
+const char *
+icpGetUrl(const Ip::Address &from, const char * const buf, const icp_common_t &header)
+{
+    const auto receivedPacketSize = static_cast<size_t>(header.length);
+    const auto payloadOffset = sizeof(header);
+
+    // Query payload contains a "Requester Host Address" followed by a URL.
+    // Payload of other ICP packets (with opcode that we recognize) is a URL.
+    const auto urlOffset = payloadOffset + ((header.opcode == ICP_QUERY) ? sizeof(uint32_t) : 0);
+
+    // A URL field cannot be empty because it includes a terminating NUL char.
+    // Ensure that the packet has at least one URL field byte.
+    if (urlOffset >= receivedPacketSize) {
+        debugs(12, 3, "too small packet from " << from << ": " << urlOffset << " >= " << receivedPacketSize);
+        return nullptr;
+    }
+
+    // All ICP packets (with opcode that we recognize) _end_ with a URL field.
+    // RFC 2186 requires all URLs to be "Null-Terminated".
+    if (buf[receivedPacketSize - 1] != '\0') {
+        debugs(12, 3, "unterminated URL or trailing garbage from " << from);
+        return nullptr;
+    }
+
+    const auto url = buf + urlOffset; // a possibly empty c-string
+    if (urlOffset + strlen(url) + 1 != receivedPacketSize) {
+        debugs(12, 3, "URL with an embedded NUL or trailing garbage from " << from);
+        return nullptr;
+    }
+
+    return url;
+}
+
+HttpRequest::Pointer
+icpGetRequest(const char * const url, const int reqnum, const int fd, const Ip::Address &from)
 {
     if (strpbrk(url, w_space)) {
-        url = rfc1738_escape(url);
         icpCreateAndSend(ICP_ERR, 0, rfc1738_escape(url), reqnum, 0, fd, from, nullptr);
         return nullptr;
     }
 
     const auto mx = MasterXaction::MakePortless<XactionInitiator::initIcp>();
-    auto *result = HttpRequest::FromUrlXXX(url, mx);
-    if (!result)
-        icpCreateAndSend(ICP_ERR, 0, url, reqnum, 0, fd, from, nullptr);
+    if (const HttpRequest::Pointer request = HttpRequest::FromUrlXXX(url, mx)) {
+        if (!icpAccessAllowed(from, request.getRaw())) {
+            icpDenyAccess(from, url, reqnum, fd);
+            return nullptr;
+        }
 
-    return result;
+        return request;
+    }
 
+    icpCreateAndSend(ICP_ERR, 0, url, reqnum, 0, fd, from, nullptr);
+    return nullptr;
 }
 
 static void
-doV2Query(int fd, Ip::Address &from, char *buf, icp_common_t header)
+doV2Query(const int fd, Ip::Address &from, const char * const buf, icp_common_t header)
 {
     int rtt = 0;
     int src_rtt = 0;
     uint32_t flags = 0;
-    /* We have a valid packet */
-    char *url = buf + sizeof(icp_common_t) + sizeof(uint32_t);
-    HttpRequest *icp_request = icpGetRequest(url, header.reqnum, fd, from);
 
-    if (!icp_request)
+    const auto url = icpGetUrl(from, buf, header);
+    if (!url) {
+        icpCreateAndSend(ICP_ERR, 0, "", header.reqnum, 0, fd, from, nullptr);
         return;
+    }
 
-    HTTPMSGLOCK(icp_request);
+    const auto icp_request = icpGetRequest(url, header.reqnum, fd, from);
 
-    if (!icpAccessAllowed(from, icp_request)) {
-        icpDenyAccess(from, url, header.reqnum, fd);
-        HTTPMSGUNLOCK(icp_request);
+    if (!icp_request)
         return;
-    }
+
 #if USE_ICMP
     if (header.flags & ICP_FLAG_SRC_RTT) {
         rtt = netdbHostRtt(icp_request->url.host());
@@ -503,7 +539,7 @@
 #endif /* USE_ICMP */
 
     /* The peer is allowed to use this cache */
-    ICP2State state(header, icp_request);
+    ICP2State state(header, icp_request.getRaw());
     state.fd = fd;
     state.from = from;
     state.url = xstrdup(url);
@@ -532,8 +568,6 @@
     }
 
     icpCreateAndSend(codeToSend, flags, url, header.reqnum, src_rtt, fd, from, state.al);
-
-    HTTPMSGUNLOCK(icp_request);
 }
 
 void
@@ -545,7 +579,10 @@
         neighbors_do_private_keys = 0;
     }
 
-    char *url = buf + sizeof(icp_common_t);
+	
+    const auto url = icpGetUrl(from, buf, *this);
+    if (!url)
+        return;
     debugs(12, 3, "icpHandleIcpV2: " << icp_opcode_str[opcode] << " from " << from << " for '" << url << "'");
 
     const cache_key *key = icpGetCacheKey(url, (int) reqnum);
@@ -680,7 +717,10 @@
 
         icp_version = (int) buf[1]; /* cheat! */
 
-        if (icpOutgoingConn->local == from)
+        // XXX: The IP equality comparison below ignores port differences but
+        // should not. It also fails to detect loops when `local` is a wildcard
+        // address (e.g., [::]:3130) because `from` address is never a wildcard.
+        if (icpOutgoingConn && icpOutgoingConn->local == from)
             // ignore ICP packets which loop back (multicast usually)
             debugs(12, 4, "icpHandleUdp: Ignoring UDP packet sent by myself");
         else if (icp_version == ICP_VERSION_2)
