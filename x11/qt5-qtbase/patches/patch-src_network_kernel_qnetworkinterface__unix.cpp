$NetBSD: patch-src_network_kernel_qnetworkinterface__unix.cpp,v 1.1 2018/01/31 12:36:57 jperkin Exp $

Support ifr_index.

--- src/network/kernel/qnetworkinterface_unix.cpp.orig	2017-11-30 13:49:46.000000000 +0000
+++ src/network/kernel/qnetworkinterface_unix.cpp
@@ -136,7 +136,11 @@ uint QNetworkInterfaceManager::interface
 
     uint id = 0;
     if (qt_safe_ioctl(socket, SIOCGIFINDEX, &req) >= 0)
+#ifdef ifr_ifindex
         id = req.ifr_ifindex;
+#else
+        id = req.ifr_index;
+#endif
     qt_safe_close(socket);
     return id;
 #else
@@ -155,7 +159,11 @@ QString QNetworkInterfaceManager::interf
     int socket = qt_safe_socket(AF_INET, SOCK_STREAM, 0);
     if (socket >= 0) {
         memset(&req, 0, sizeof(ifreq));
+#ifdef ifr_ifindex
         req.ifr_ifindex = index;
+#else
+        req.ifr_index = index;
+#endif
 
         if (qt_safe_ioctl(socket, SIOCGIFNAME, &req) >= 0) {
             qt_safe_close(socket);
@@ -232,10 +240,10 @@ static QNetworkInterfacePrivate *findInt
     // Get the interface index
 #  ifdef SIOCGIFINDEX
     if (qt_safe_ioctl(socket, SIOCGIFINDEX, &req) >= 0)
-#    if defined(Q_OS_HAIKU)
-        ifindex = req.ifr_index;
-#    else
+#    ifdef ifr_ifindex
         ifindex = req.ifr_ifindex;
+#    else
+        ifindex = req.ifr_index;
 #    endif
 #  else
     ifindex = if_nametoindex(req.ifr_name);
