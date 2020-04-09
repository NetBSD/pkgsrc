$NetBSD: patch-src_ip_Intercept.cc,v 1.1 2020/04/09 09:45:20 sborrill Exp $

Fix: use correct #if to look for IPv6 support

--- src/ip/Intercept.cc.orig	2020-01-20 02:51:40.000000000 +0000
+++ src/ip/Intercept.cc	2020-04-09 08:58:13.000000000 +0100
@@ -204,7 +204,7 @@
     memset(&natLookup, 0, sizeof(natLookup));
     // for NAT lookup set local and remote IP:port's
     if (newConn->remote.isIPv6()) {
-#if HAVE_NATLOOKUP_NL_INIPADDR_IN6
+#if HAVE_STRUCT_NATLOOKUP_NL_INIPADDR_IN6
         natLookup.nl_v = 6;
         newConn->local.getInAddr(natLookup.nl_inipaddr.in6);
         newConn->remote.getInAddr(natLookup.nl_outipaddr.in6);
@@ -292,7 +292,7 @@
         debugs(89, 9, HERE << "address: " << newConn);
         return false;
     } else {
-#if HAVE_NATLOOKUP_NL_REALIPADDR_IN6
+#if HAVE_STRUCT_NATLOOKUP_NL_REALIPADDR_IN6
         if (newConn->remote.isIPv6())
             newConn->local = natLookup.nl_realipaddr.in6;
         else
