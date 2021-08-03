$NetBSD: patch-src_3rdparty_chromium_net_dns_dns__util.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/net/dns/dns_util.cc.orig	2020-07-15 18:56:00.000000000 +0000
+++ src/3rdparty/chromium/net/dns/dns_util.cc
@@ -40,6 +40,7 @@ const uint16_t kFlagNamePointer = 0xc000
 }  // namespace
 
 #if defined(OS_POSIX)
+#include <sys/socket.h>
 #include <netinet/in.h>
 #if !defined(OS_NACL)
 #include <net/if.h>
