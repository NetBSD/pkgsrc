$NetBSD: patch-Source_WebCore_platform_network_DNS.h,v 1.2 2021/09/28 22:11:54 leot Exp $

Include sys/socket.h for AF_*.

--- Source/WebCore/platform/network/DNS.h.orig	2021-09-01 09:16:50.000000000 +0000
+++ Source/WebCore/platform/network/DNS.h
@@ -34,6 +34,7 @@
 #include <ws2tcpip.h>
 #else
 #include <netinet/in.h>
+#include <sys/socket.h>
 #endif
 
 namespace WebCore {
