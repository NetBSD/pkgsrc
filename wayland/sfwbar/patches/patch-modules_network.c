$NetBSD: patch-modules_network.c,v 1.1 2026/04/14 12:53:47 kikadf Exp $

* Add NetBSD support

--- modules/network.c.orig	2026-02-15 14:18:39.000000000 +0000
+++ modules/network.c
@@ -374,7 +374,7 @@ static gboolean net_rt_parse (GIOChannel
   return TRUE;
 }
 
-#elif defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 
 #include <net/if_dl.h>
 #include <net/route.h>
@@ -414,7 +414,10 @@ static void net_update_traffic ( gchar *
   freeifaddrs(addrs);
 }
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
+#if defined (__NetBSD__)
+#define COMPAT_FREEBSD_NET80211
+#endif
 #include <net80211/ieee80211_ioctl.h>
 
 static void net_update_essid ( char *interface )
@@ -490,7 +493,11 @@ static gdouble net_get_signal ( gchar *i
   req.i_len = sizeof(nfo);
   (void)g_strlcpy(req.i_name, interface, sizeof(req.i_name));
   if(ioctl(sock, SIOCG80211, &req) >=0)
+#if defined(__NetBSD__)
+    rssi = nfo.sreq.info[0].isi_rssi/2;
+#else
     rssi = nfo.sreq.info[0].isi_noise + nfo.sreq.info[0].isi_rssi/2;
+#endif
   else
     rssi = -100;
   close(sock);
