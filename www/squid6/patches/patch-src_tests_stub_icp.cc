$NetBSD: patch-src_tests_stub_icp.cc,v 1.1 2026/03/25 11:47:47 sborrill Exp $

Backport fixes for:
SQUID-2026:2 Denial of Service in ICP Request handling (CVE-2026-32748)
SQUID-2026:3 Out of Bounds Read in ICP message handling (CVE-2026-33515)

https://github.com/squid-cache/squid/commit/703e07d25ca6fa11f52d20bf0bb879e22ab7481b
https://github.com/squid-cache/squid/commit/8138e909d2058d4401e0ad49b583afaec912b165

--- src/tests/stub_icp.cc.orig	2025-06-24 08:49:30.000000000 +0100
+++ src/tests/stub_icp.cc	2026-03-25 09:26:15.507715616 +0000
@@ -9,6 +9,7 @@
 #include "squid.h"
 #include "AccessLogEntry.h"
 #include "comm/Connection.h"
+#include "HttpRequest.h"
 #include "ICP.h"
 
 #define STUB_API "icp_*.cc"
@@ -29,11 +30,11 @@
 Comm::ConnectionPointer icpOutgoingConn;
 Ip::Address theIcpPublicHostID;
 
-HttpRequest* icpGetRequest(char *, int, int, Ip::Address &) STUB_RETVAL(nullptr)
-bool icpAccessAllowed(Ip::Address &, HttpRequest *) STUB_RETVAL(false)
+const char *icpGetUrl(const Ip::Address &, const char *, const icp_common_t &) STUB_RETVAL(nullptr)
+HttpRequest::Pointer icpGetRequest(char *, int, int, Ip::Address &) STUB_RETVAL(nullptr)
 void icpCreateAndSend(icp_opcode, int, char const *, int, int, int, const Ip::Address &, AccessLogEntryPointer) STUB
 icp_opcode icpGetCommonOpcode() STUB_RETVAL(ICP_INVALID)
-void icpDenyAccess(Ip::Address &, char *, int, int) STUB
+void icpDenyAccess(const Ip::Address &, const char *, int, int) STUB
 void icpHandleIcpV3(int, Ip::Address &, char *, int) STUB
 void icpConnectionShutdown(void) STUB
 int icpSetCacheKey(const cache_key *) STUB_RETVAL(0)
