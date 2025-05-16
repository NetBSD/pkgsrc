$NetBSD: patch-net_dns_public_resolv__reader.cc,v 1.2 2025/05/16 16:08:28 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/dns/public/resolv_reader.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ net/dns/public/resolv_reader.cc
@@ -40,7 +40,7 @@ std::optional<std::vector<IPEndPoint>> G
   if (!(res.options & RES_INIT))
     return std::nullopt;
 
-#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_FREEBSD)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_NETBSD)
   union res_sockaddr_union addresses[MAXNS];
   int nscount = res_getservers(const_cast<res_state>(&res), addresses, MAXNS);
   DCHECK_GE(nscount, 0);
