$NetBSD: patch-src_3rdparty_chromium_net_dns_dns__reloader.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/net/dns/dns_reloader.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/net/dns/dns_reloader.cc
@@ -7,6 +7,10 @@
 #if defined(OS_POSIX) && !defined(OS_APPLE) && !defined(OS_OPENBSD) && \
     !defined(OS_ANDROID) && !defined(OS_FUCHSIA)
 
+#if defined(OS_BSD)
+#include <netinet/in.h>
+#endif
+
 #include <resolv.h>
 
 #include "base/lazy_instance.h"
