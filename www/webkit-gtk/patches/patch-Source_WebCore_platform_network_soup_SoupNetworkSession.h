$NetBSD: patch-Source_WebCore_platform_network_soup_SoupNetworkSession.h,v 1.3 2018/05/15 15:21:04 wiz Exp $

Add missing header for URL type.

--- Source/WebCore/platform/network/soup/SoupNetworkSession.h.orig	2018-05-07 08:56:05.000000000 +0000
+++ Source/WebCore/platform/network/soup/SoupNetworkSession.h
@@ -26,6 +26,7 @@
 #ifndef SoupNetworkSession_h
 #define SoupNetworkSession_h
 
+#include <URL.h>
 #include <gio/gio.h>
 #include <pal/SessionID.h>
 #include <wtf/Function.h>
