$NetBSD: patch-Source_WebCore_platform_network_soup_SoupNetworkSession.h,v 1.1 2018/05/14 21:22:34 wiz Exp $

Add missing header for URL type.

--- Source/WebCore/platform/network/soup/SoupNetworkSession.h.orig	2018-05-07 08:56:05.000000000 +0000
+++ Source/WebCore/platform/network/soup/SoupNetworkSession.h
@@ -32,6 +32,7 @@
 #include <wtf/Noncopyable.h>
 #include <wtf/glib/GRefPtr.h>
 #include <wtf/text/WTFString.h>
+#include <URL.h>
 
 typedef struct _SoupCache SoupCache;
 typedef struct _SoupCookieJar SoupCookieJar;
