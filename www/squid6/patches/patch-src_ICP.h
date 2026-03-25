$NetBSD: patch-src_ICP.h,v 1.1 2026/03/25 11:47:46 sborrill Exp $

Backport fixes for:
SQUID-2026:2 Denial of Service in ICP Request handling (CVE-2026-32748)
SQUID-2026:3 Out of Bounds Read in ICP message handling (CVE-2026-33515)

https://github.com/squid-cache/squid/commit/703e07d25ca6fa11f52d20bf0bb879e22ab7481b
https://github.com/squid-cache/squid/commit/8138e909d2058d4401e0ad49b583afaec912b165

--- src/ICP.h.orig	2025-06-24 08:49:30.000000000 +0100
+++ src/ICP.h	2026-03-25 09:16:20.439240148 +0000
@@ -89,11 +89,12 @@
 extern Comm::ConnectionPointer icpOutgoingConn;
 extern Ip::Address theIcpPublicHostID;
 
-/// \ingroup ServerProtocolICPAPI
-HttpRequest* icpGetRequest(char *url, int reqnum, int fd, Ip::Address &from);
+/// A URI extracted from the given raw packet buffer.
+/// On errors, details the problem and returns nil.
+const char *icpGetUrl(const Ip::Address &from, const char *, const icp_common_t &);
 
 /// \ingroup ServerProtocolICPAPI
-bool icpAccessAllowed(Ip::Address &from, HttpRequest * icp_request);
+HttpRequestPointer icpGetRequest(const char *url, int reqnum, int fd, const Ip::Address &from);
 
 /// \ingroup ServerProtocolICPAPI
 void icpCreateAndSend(icp_opcode, int flags, char const *url, int reqnum, int pad, int fd, const Ip::Address &from, AccessLogEntryPointer);
@@ -102,7 +103,7 @@
 icp_opcode icpGetCommonOpcode();
 
 /// \ingroup ServerProtocolICPAPI
-void icpDenyAccess(Ip::Address &from, char *url, int reqnum, int fd);
+void icpDenyAccess(const Ip::Address &from, const char *url, int reqnum, int fd);
 
 /// \ingroup ServerProtocolICPAPI
 PF icpHandleUdp;
