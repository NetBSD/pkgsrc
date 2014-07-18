$NetBSD: patch-lib_url.c,v 1.1 2014/07/18 09:04:43 ryoon Exp $

* SCO OpenServer 5.0.7/3.2 has no if_nametoindex(3).

--- lib/url.c.orig	2014-05-20 08:34:01.000000000 +0000
+++ lib/url.c
@@ -4004,7 +4004,7 @@ static CURLcode parseurlandfillconn(stru
       }
       else {
         /* Zone identifier is not numeric */
-#if defined(HAVE_NET_IF_H) && defined(IFNAMSIZ)
+#if defined(HAVE_NET_IF_H) && defined(IFNAMSIZ) && !defined(_SCO_DS)
         char ifname[IFNAMSIZ + 2];
         char *square_bracket;
         unsigned int scopeidx = 0;
