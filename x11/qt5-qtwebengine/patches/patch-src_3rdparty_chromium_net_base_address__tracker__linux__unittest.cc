$NetBSD: patch-src_3rdparty_chromium_net_base_address__tracker__linux__unittest.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/net/base/address_tracker_linux_unittest.cc.orig	2020-07-15 18:56:00.000000000 +0000
+++ src/3rdparty/chromium/net/base/address_tracker_linux_unittest.cc
@@ -4,7 +4,11 @@
 
 #include "net/base/address_tracker_linux.h"
 
+#if defined(OS_LINUX)
 #include <linux/if.h>
+#else
+#include <net/if.h>
+#endif
 
 #include <memory>
 #include <unordered_set>
