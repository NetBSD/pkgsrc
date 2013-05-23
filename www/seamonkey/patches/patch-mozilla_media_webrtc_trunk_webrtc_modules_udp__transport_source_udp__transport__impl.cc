$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_modules_udp__transport_source_udp__transport__impl.cc,v 1.1 2013/05/23 13:25:30 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/modules/udp_transport/source/udp_transport_impl.cc.orig	2013-05-03 03:08:07.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/modules/udp_transport/source/udp_transport_impl.cc
@@ -18,16 +18,16 @@
 #if defined(_WIN32)
 #include <winsock2.h>
 #include <ws2tcpip.h>
-#elif defined(WEBRTC_LINUX) || defined(WEBRTC_MAC)
+#elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
 #include <arpa/inet.h>
 #include <ctype.h>
 #include <fcntl.h>
 #include <netdb.h>
+#include <sys/socket.h>
 #include <net/if.h>
 #include <netinet/in.h>
 #include <stdlib.h>
 #include <sys/ioctl.h>
-#include <sys/socket.h>
 #include <sys/time.h>
 #include <unistd.h>
 #ifndef WEBRTC_IOS
@@ -36,9 +36,11 @@
 #endif // defined(WEBRTC_LINUX) || defined(WEBRTC_MAC)
 
 #if defined(WEBRTC_MAC)
-#include <ifaddrs.h>
 #include <machine/types.h>
 #endif
+#if defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
+#include <ifaddrs.h>
+#endif
 #if defined(WEBRTC_LINUX)
 #include <linux/netlink.h>
 #include <linux/rtnetlink.h>
@@ -51,7 +53,7 @@
 #include "typedefs.h"
 #include "udp_socket_manager_wrapper.h"
 
-#if defined(WEBRTC_LINUX) || defined(WEBRTC_MAC)
+#if defined(WEBRTC_LINUX) || defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
 #define GetLastError() errno
 
 #define IFRSIZE ((int)(size * sizeof (struct ifreq)))
@@ -61,7 +63,7 @@
    (int)(nlh)->nlmsg_len >= (int)sizeof(struct nlmsghdr) &&             \
    (int)(nlh)->nlmsg_len <= (len))
 
-#endif // defined(WEBRTC_LINUX) || defined(WEBRTC_MAC)
+#endif // defined(WEBRTC_LINUX) || defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
 
 namespace webrtc {
 
@@ -2371,7 +2373,7 @@ WebRtc_Word32 UdpTransport::InetPresenta
                                                       const char* src,
                                                       void* dst)
 {
-#if defined(WEBRTC_LINUX) || defined(WEBRTC_MAC)
+#if defined(WEBRTC_LINUX) || defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
     const WebRtc_Word32 result = inet_pton(af, src, dst);
     return result > 0 ? 0 : -1;
 
@@ -2493,7 +2495,7 @@ WebRtc_Word32 UdpTransport::LocalHostAdd
                  "getaddrinfo failed to find address");
     return -1;
 
-#elif defined(WEBRTC_MAC)
+#elif defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
     struct ifaddrs* ptrIfAddrs = NULL;
     struct ifaddrs* ptrIfAddrsStart = NULL;
 
@@ -2685,7 +2687,7 @@ WebRtc_Word32 UdpTransport::LocalHostAdd
                      "gethostbyname failed, error:%d", error);
         return -1;
     }
-#elif (defined(WEBRTC_MAC))
+#elif (defined(WEBRTC_BSD) || defined(WEBRTC_MAC))
     char localname[255];
     if (gethostname(localname, 255) != -1)
     {
@@ -2824,7 +2826,7 @@ WebRtc_Word32 UdpTransport::IPAddress(co
     sourcePort = htons(source_port);
     return 0;
 
- #elif defined(WEBRTC_LINUX) || defined(WEBRTC_MAC)
+ #elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
     WebRtc_Word32 ipFamily = address._sockaddr_storage.sin_family;
     const void* ptrNumericIP = NULL;
 
