$NetBSD: patch-net_dns_public_resolv__reader.cc,v 1.13 2025/12/23 13:22:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/dns/public/resolv_reader.cc.orig	2025-12-17 23:05:18.000000000 +0000
+++ net/dns/public/resolv_reader.cc
@@ -34,7 +34,7 @@ std::unique_ptr<ScopedResState> ResolvRe
 }
 
 bool ResolvReader::IsLikelySystemdResolved() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   // Look for a single 127.0.0.53:53 nameserver endpoint. The only known
   // significant usage of such a configuration is the systemd-resolved local
   // resolver, so it is then a fairly safe assumption that any DNS queries to
@@ -64,7 +64,7 @@ std::optional<std::vector<IPEndPoint>> G
   if (!(res.options & RES_INIT))
     return std::nullopt;
 
-#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_FREEBSD)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_NETBSD)
   union res_sockaddr_union addresses[MAXNS];
   int nscount = res_getservers(const_cast<res_state>(&res), addresses, MAXNS);
   DCHECK_GE(nscount, 0);
