$NetBSD: patch-src_3rdparty_chromium_net_dns_dns__config__service__posix__unittest.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/net/dns/dns_config_service_posix_unittest.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/net/dns/dns_config_service_posix_unittest.cc
@@ -51,7 +51,7 @@ const char* const kNameserversIPv4[] = {
     "1.0.0.1",
 };
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 const char* const kNameserversIPv6[] = {
     NULL,
     "2001:DB8:0::42",
@@ -87,7 +87,7 @@ void InitializeResState(res_state res) {
     ++res->nscount;
   }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Install IPv6 addresses, replacing the corresponding IPv4 addresses.
   unsigned nscount6 = 0;
   for (unsigned i = 0; i < base::size(kNameserversIPv6) && i < MAXNS; ++i) {
@@ -108,7 +108,7 @@ void InitializeResState(res_state res) {
 }
 
 void CloseResState(res_state res) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   for (int i = 0; i < res->nscount; ++i) {
     if (res->_u._ext.nsaddrs[i] != NULL)
       free(res->_u._ext.nsaddrs[i]);
@@ -133,7 +133,7 @@ void InitializeExpectedConfig(DnsConfig*
     config->nameservers.push_back(IPEndPoint(ip, NS_DEFAULTPORT + i));
   }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   for (unsigned i = 0; i < base::size(kNameserversIPv6) && i < MAXNS; ++i) {
     if (!kNameserversIPv6[i])
       continue;
