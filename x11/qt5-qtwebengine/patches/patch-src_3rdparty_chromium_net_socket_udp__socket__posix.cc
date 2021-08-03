$NetBSD: patch-src_3rdparty_chromium_net_socket_udp__socket__posix.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/net/socket/udp_socket_posix.cc.orig	2020-07-15 18:56:00.000000000 +0000
+++ src/3rdparty/chromium/net/socket/udp_socket_posix.cc
@@ -70,7 +70,7 @@ const int kActivityMonitorMinimumSamples
 const base::TimeDelta kActivityMonitorMsThreshold =
     base::TimeDelta::FromMilliseconds(100);
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 // When enabling multicast using setsockopt(IP_MULTICAST_IF) MacOS
 // requires passing IPv4 address instead of interface index. This function
 // resolves IPv4 address by interface index. The |address| is returned in
@@ -645,7 +645,7 @@ int UDPSocketPosix::SetDoNotFragment() {
 }
 
 void UDPSocketPosix::SetMsgConfirm(bool confirm) {
-#if !defined(OS_MACOSX) && !defined(OS_IOS)
+#if !defined(OS_MACOSX) && !defined(OS_IOS) && !defined(OS_BSD)
   if (confirm) {
     sendto_flags_ |= MSG_CONFIRM;
   } else {
@@ -666,13 +666,16 @@ int UDPSocketPosix::SetBroadcast(bool br
   DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
   int value = broadcast ? 1 : 0;
   int rv;
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   // SO_REUSEPORT on OSX permits multiple processes to each receive
   // UDP multicast or broadcast datagrams destined for the bound
   // port.
   // This is only being set on OSX because its behavior is platform dependent
   // and we are playing it safe by only setting it on platforms where things
   // break.
+  rv = setsockopt(socket_, SOL_SOCKET, SO_REUSEADDR, &value, sizeof(value));
+  if (rv != 0)
+    return MapSystemError(errno);
   rv = setsockopt(socket_, SOL_SOCKET, SO_REUSEPORT, &value, sizeof(value));
   if (rv != 0)
     return MapSystemError(errno);
@@ -936,7 +939,7 @@ int UDPSocketPosix::SetMulticastOptions(
   if (multicast_interface_ != 0) {
     switch (addr_family_) {
       case AF_INET: {
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
         ip_mreq mreq = {};
         int error = GetIPv4AddressFromIndex(socket_, multicast_interface_,
                                             &mreq.imr_interface.s_addr);
@@ -948,7 +951,11 @@ int UDPSocketPosix::SetMulticastOptions(
         mreq.imr_address.s_addr = htonl(INADDR_ANY);
 #endif  //  !defined(OS_MACOSX)
         int rv = setsockopt(socket_, IPPROTO_IP, IP_MULTICAST_IF,
+#if defined(OS_BSD)
+                            reinterpret_cast<const char*>(&mreq.imr_interface.s_addr), sizeof(mreq.imr_interface.s_addr));
+#else
                             reinterpret_cast<const char*>(&mreq), sizeof(mreq));
+#endif
         if (rv)
           return MapSystemError(errno);
         break;
@@ -1010,7 +1017,7 @@ int UDPSocketPosix::JoinGroup(const IPAd
       if (addr_family_ != AF_INET)
         return ERR_ADDRESS_INVALID;
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
       ip_mreq mreq = {};
       int error = GetIPv4AddressFromIndex(socket_, multicast_interface_,
                                           &mreq.imr_interface.s_addr);
@@ -1058,9 +1065,18 @@ int UDPSocketPosix::LeaveGroup(const IPA
     case IPAddress::kIPv4AddressSize: {
       if (addr_family_ != AF_INET)
         return ERR_ADDRESS_INVALID;
+#if defined(OS_BSD)
+      ip_mreq mreq = {};
+      int error = GetIPv4AddressFromIndex(socket_, multicast_interface_,
+                                          &mreq.imr_interface.s_addr);
+
+      if (error != OK)
+        return error;
+#else
       ip_mreqn mreq = {};
       mreq.imr_ifindex = multicast_interface_;
       mreq.imr_address.s_addr = INADDR_ANY;
+#endif
       memcpy(&mreq.imr_multiaddr, group_address.bytes().data(),
              IPAddress::kIPv4AddressSize);
       int rv = setsockopt(socket_, IPPROTO_IP, IP_DROP_MEMBERSHIP,
