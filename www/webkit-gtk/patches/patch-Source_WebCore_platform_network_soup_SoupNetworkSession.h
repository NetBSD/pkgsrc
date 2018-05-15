$NetBSD: patch-Source_WebCore_platform_network_soup_SoupNetworkSession.h,v 1.2 2018/05/15 08:32:37 wiz Exp $

Add missing header for URL type.

--- Source/WebCore/platform/network/soup/SoupNetworkSession.h.orig	2018-05-07 08:56:05.000000000 +0000
+++ Source/WebCore/platform/network/soup/SoupNetworkSession.h
@@ -28,6 +28,7 @@
 
 #include <gio/gio.h>
 #include <pal/SessionID.h>
+#include <URL.h>
 #include <wtf/Function.h>
 #include <wtf/Noncopyable.h>
 #include <wtf/glib/GRefPtr.h>
