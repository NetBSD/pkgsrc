$NetBSD: patch-src_ip_Intercept.cc,v 1.5 2015/08/17 16:39:38 prlw1 Exp $

Fix transparent proxying with IPFilter 5
http://bugs.squid-cache.org/show_bug.cgi?id=4302

--- src/ip/Intercept.cc.orig	2015-08-01 06:08:17.000000000 +0000
+++ src/ip/Intercept.cc
@@ -200,6 +200,19 @@ Ip::Intercept::IpfInterception(const Com
     // all fields must be set to 0
     memset(&natLookup, 0, sizeof(natLookup));
     // for NAT lookup set local and remote IP:port's
+    if (newConn->remote.isIPv6()) {
+#if IPFILTER_VERSION < 5000003
+        // warn once every 10 at critical level, then push down a level each repeated event
+        static int warningLevel = DBG_CRITICAL;
+        debugs(89, warningLevel, "IPF (IPFilter v4) NAT does not support IPv6. Please upgrade to IPFilter v5.1");
+        warningLevel = ++warningLevel % 10;
+        return false;
+#else
+        natLookup.nl_v = 6;
+    } else {
+        natLookup.nl_v = 4;
+#endif
+    }
     natLookup.nl_inport = htons(newConn->local.port());
     newConn->local.getInAddr(natLookup.nl_inip);
     natLookup.nl_outport = htons(newConn->remote.port());
