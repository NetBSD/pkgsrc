$NetBSD: patch-Source_WebCore_platform_network_DNS.h,v 1.1 2021/01/12 15:21:31 jperkin Exp $

Include sys/socket.h for AF_*.

--- Source/WebCore/platform/network/DNS.h.orig	2020-08-12 09:17:55.000000000 +0000
+++ Source/WebCore/platform/network/DNS.h
@@ -30,6 +30,7 @@
 #include <ws2tcpip.h>
 #else
 #include <netinet/in.h>
+#include <sys/socket.h>
 #endif
 
 #include <wtf/Forward.h>
