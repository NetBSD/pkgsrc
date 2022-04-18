$NetBSD: patch-src_3rdparty_chromium_net_dns_host__resolver__proc.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/net/dns/host_resolver_proc.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/net/dns/host_resolver_proc.cc
@@ -159,7 +159,7 @@ int SystemHostResolverCall(const std::st
   base::ScopedBlockingCall scoped_blocking_call(FROM_HERE,
                                                 base::BlockingType::WILL_BLOCK);
 
-#if defined(OS_POSIX) && !defined(OS_APPLE) && !defined(OS_OPENBSD) && \
+#if defined(OS_POSIX) && !defined(OS_APPLE) && !defined(OS_BSD) && \
     !defined(OS_ANDROID) && !defined(OS_FUCHSIA)
   DnsReloaderMaybeReload();
 #endif
