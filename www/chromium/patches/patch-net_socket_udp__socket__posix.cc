$NetBSD: patch-net_socket_udp__socket__posix.cc,v 1.14 2026/01/19 16:14:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/socket/udp_socket_posix.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ net/socket/udp_socket_posix.cc
@@ -78,6 +78,32 @@ constexpr int kBindRetries = 10;
 constexpr int kPortStart = 1024;
 constexpr int kPortEnd = 65535;
 
+#if BUILDFLAG(IS_NETBSD)
+int GetIPv4AddressFromIndex(int socket, uint32_t index, uint32_t* address) {
+  if (!index) {
+    *address = htonl(INADDR_ANY);
+    return OK;
+  }
+
+  sockaddr_in* result = nullptr;
+
+  ifreq ifr;
+  ifr.ifr_addr.sa_family = AF_INET;
+  if (!if_indextoname(index, ifr.ifr_name))
+    return MapSystemError(errno);
+  int rv = ioctl(socket, SIOCGIFADDR, &ifr);
+  if (rv == -1)
+    return MapSystemError(errno);
+  result = reinterpret_cast<sockaddr_in*>(&ifr.ifr_addr);
+
+  if (!result)
+    return ERR_ADDRESS_INVALID;
+
+  *address = result->sin_addr.s_addr;
+  return OK;
+}
+#endif
+
 int GetSocketFDHash(int fd) {
   return fd ^ 1595649551;
 }
@@ -559,12 +585,17 @@ int UDPSocketPosix::SetRecvTos() {
 #endif  // BUILDFLAG(IS_APPLE)
   }
 
+#ifdef IP_RECVTOS
   int rv = setsockopt(socket_, IPPROTO_IP, IP_RECVTOS, &ecn, sizeof(ecn));
+#else
+  int rv = -1;
+  errno = EOPNOTSUPP;
+#endif
   return rv == 0 ? OK : MapSystemError(errno);
 }
 
 void UDPSocketPosix::SetMsgConfirm(bool confirm) {
-#if !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
   if (confirm) {
     sendto_flags_ |= MSG_CONFIRM;
   } else {
@@ -585,7 +616,7 @@ int UDPSocketPosix::SetBroadcast(bool br
   DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
   int value = broadcast ? 1 : 0;
   int rv;
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   // SO_REUSEPORT on OSX permits multiple processes to each receive
   // UDP multicast or broadcast datagrams destined for the bound
   // port.
@@ -906,9 +937,17 @@ int UDPSocketPosix::SetMulticastOptions(
   if (multicast_interface_ != 0) {
     switch (addr_family_) {
       case AF_INET: {
+#if BUILDFLAG(IS_NETBSD)
+        ip_mreq mreq = {};
+        int error = GetIPv4AddressFromIndex(socket_, multicast_interface_,
+                                            &mreq.imr_interface.s_addr);
+        if (error != OK)
+          return error;
+#else
         ip_mreqn mreq = {};
         mreq.imr_ifindex = multicast_interface_;
         mreq.imr_address.s_addr = htonl(INADDR_ANY);
+#endif
         int rv = setsockopt(socket_, IPPROTO_IP, IP_MULTICAST_IF,
                             reinterpret_cast<const char*>(&mreq), sizeof(mreq));
         if (rv)
@@ -943,7 +982,7 @@ int UDPSocketPosix::DoBind(const IPEndPo
 #if BUILDFLAG(IS_CHROMEOS)
   if (last_error == EINVAL)
     return ERR_ADDRESS_IN_USE;
-#elif BUILDFLAG(IS_APPLE)
+#elif BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   if (last_error == EADDRNOTAVAIL)
     return ERR_ADDRESS_IN_USE;
 #endif
@@ -971,9 +1010,17 @@ int UDPSocketPosix::JoinGroup(const IPAd
     case IPAddress::kIPv4AddressSize: {
       if (addr_family_ != AF_INET)
         return ERR_ADDRESS_INVALID;
+#if BUILDFLAG(IS_NETBSD)
+      ip_mreq mreq = {};
+      int error = GetIPv4AddressFromIndex(socket_, multicast_interface_,
+                                          &mreq.imr_interface.s_addr);
+      if (error != OK)
+        return error;
+#else
       ip_mreqn mreq = {};
       mreq.imr_ifindex = multicast_interface_;
       mreq.imr_address.s_addr = htonl(INADDR_ANY);
+#endif
       mreq.imr_multiaddr = ToInAddr(group_address);
       int rv = setsockopt(socket_, IPPROTO_IP, IP_ADD_MEMBERSHIP,
                           &mreq, sizeof(mreq));
@@ -1008,9 +1055,17 @@ int UDPSocketPosix::LeaveGroup(const IPA
     case IPAddress::kIPv4AddressSize: {
       if (addr_family_ != AF_INET)
         return ERR_ADDRESS_INVALID;
+#if BUILDFLAG(IS_NETBSD)
+      ip_mreq mreq = {};
+      int error = GetIPv4AddressFromIndex(socket_, multicast_interface_,
+                                          &mreq.imr_interface.s_addr);
+      if (error != OK)
+        return error;
+#else
       ip_mreqn mreq = {};
       mreq.imr_ifindex = multicast_interface_;
       mreq.imr_address.s_addr = INADDR_ANY;
+#endif
       mreq.imr_multiaddr = ToInAddr(group_address);
       int rv = setsockopt(socket_, IPPROTO_IP, IP_DROP_MEMBERSHIP,
                           &mreq, sizeof(mreq));
