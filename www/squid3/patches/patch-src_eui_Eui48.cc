$NetBSD: patch-src_eui_Eui48.cc,v 1.1.2.2 2016/05/08 08:09:59 bsiegert Exp $

Fix build on NetBSD >=7.99.27 due route(4) change (deprecation of RTF_LLINFO).

--- src/eui/Eui48.cc.orig	2016-04-20 12:24:03.000000000 +0000
+++ src/eui/Eui48.cc
@@ -375,7 +375,11 @@ Eui::Eui48::lookup(const Ip::Address &c)
 
     mib[4] = NET_RT_FLAGS;
 
+#ifdef RTF_LLDATA
+    mib[5] = RTF_LLDATA;
+#else
     mib[5] = RTF_LLINFO;
+#endif
 
     if (sysctl(mib, 6, NULL, &needed, NULL, 0) < 0) {
         debugs(28, DBG_CRITICAL, "Can't estimate ARP table size!");
