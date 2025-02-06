$NetBSD: patch-net_dns_address__info.cc,v 1.1 2025/02/06 09:58:15 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/dns/address_info.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ net/dns/address_info.cc
@@ -83,8 +83,12 @@ AddressInfo::AddressInfoAndResult Addres
     // error.
     // http://crbug.com/134142
     err = ERR_NAME_NOT_RESOLVED;
-#elif BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_FREEBSD)
+#elif BUILDFLAG(IS_POSIX)
+#ifdef EAI_NODATA
     if (os_error != EAI_NONAME && os_error != EAI_NODATA)
+#else
+    if (os_error != EAI_NONAME)
+#endif
       err = ERR_NAME_RESOLUTION_FAILED;
 #endif
 
