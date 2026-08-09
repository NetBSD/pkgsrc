$NetBSD: patch-net_socket_udp__socket__posix.cc,v 1.24 2026/08/09 06:31:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/socket/udp_socket_posix.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ net/socket/udp_socket_posix.cc
@@ -77,6 +77,14 @@
 #include "base/mac/mac_util.h"
 #endif  // BUILDFLAG(IS_MAC)
 
+#if !defined(CMSG_ALIGN)
+# if defined(_ALIGN)
+#  define CMSG_ALIGN(n) _ALIGN(n)
+# elif defined(__CMSG_ALIGN)
+#  define CMSG_ALIGN(n) __CMSG_ALIGN(n)
+# endif
+#endif
+
 namespace net {
 
 namespace {
@@ -84,11 +92,37 @@ namespace {
 constexpr int kBindRetries = 10;
 constexpr int kPortStart = 1024;
 constexpr int kPortEnd = 65535;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 // Maximum number of UDP packets that can be read at a time from recvmmsg.
 constexpr size_t kMaxMmsgMessages = 128;
 #endif
 
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
@@ -181,7 +215,7 @@ uint32_t GetInterfaceForDestination(cons
 }
 #endif  // BUILDFLAG(IS_MAC)
 
-#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_IOS) && !BUILDFLAG(IS_FUCHSIA)
+#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_IOS) && !BUILDFLAG(IS_FUCHSIA) && !BUILDFLAG(IS_BSD)
 // Helper for IPv4 SSM. Sets sin_len on macOS, no-op on Linux.
 group_source_req CreateIPv4SourceGroupRequest(const IPAddress& group_address,
                                               const IPAddress& source_address,
@@ -495,7 +529,7 @@ base::expected<DatagramsMetadata, Error>
   CHECK_GT(maximum_packet_size, 0u);
   CHECK_GE(buf_len, maximum_packet_size);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   base::expected<DatagramsMetadata, Error> nread =
       InternalReadMultiple(buffer, buf_len, maximum_packet_size);
   if (nread.has_value() || nread.error() != ERR_IO_PENDING) {
@@ -777,12 +811,17 @@ int UDPSocketPosix::SetRecvTos() {
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
@@ -803,7 +842,7 @@ int UDPSocketPosix::SetBroadcast(bool br
   DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
   int value = broadcast ? 1 : 0;
   int rv;
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   // SO_REUSEPORT on OSX permits multiple processes to each receive
   // UDP multicast or broadcast datagrams destined for the bound
   // port.
@@ -1011,7 +1050,7 @@ base::expected<DatagramsMetadata, Error>
   // This read API currently only supports connected UDP sockets.
   CHECK(is_connected_);
   CHECK(remote_address_);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   return InternalRecvMmsg(buffer, buf_len / maximum_packet_size,
                           maximum_packet_size);
 #else
@@ -1019,7 +1058,7 @@ base::expected<DatagramsMetadata, Error>
 #endif
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 base::expected<DatagramsMetadata, Error> UDPSocketPosix::InternalRecvMmsg(
     IOBuffer* buffer,
     size_t num_messages,
@@ -1278,9 +1317,17 @@ int UDPSocketPosix::SetMulticastOptions(
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
@@ -1315,7 +1362,7 @@ int UDPSocketPosix::DoBind(const IPEndPo
 #if BUILDFLAG(IS_CHROMEOS)
   if (last_error == EINVAL)
     return ERR_ADDRESS_IN_USE;
-#elif BUILDFLAG(IS_APPLE)
+#elif BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   if (last_error == EADDRNOTAVAIL)
     return ERR_ADDRESS_IN_USE;
 #endif
@@ -1344,9 +1391,17 @@ int UDPSocketPosix::JoinGroup(const IPAd
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
@@ -1381,9 +1436,17 @@ int UDPSocketPosix::LeaveGroup(const IPA
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
@@ -1415,7 +1478,7 @@ int UDPSocketPosix::LeaveGroup(const IPA
 int UDPSocketPosix::SetSourceGroupMembership(const IPAddress& group_address,
                                              const IPAddress& source_address,
                                              int option) const {
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return ERR_NOT_IMPLEMENTED;
 #else
   uint32_t interface_index = multicast_interface_;
@@ -1441,6 +1504,10 @@ int UDPSocketPosix::SetSourceGroupMember
 #endif
 }
 
+#if !defined(MCAST_JOIN_SOURCE_GROUP)
+#define MCAST_JOIN_SOURCE_GROUP 0
+#endif
+
 int UDPSocketPosix::JoinSourceGroup(const IPAddress& group_address,
                                     const IPAddress& source_address) const {
   DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
@@ -1457,6 +1524,10 @@ int UDPSocketPosix::JoinSourceGroup(cons
                                   MCAST_JOIN_SOURCE_GROUP);
 }
 
+#if !defined(MCAST_LEAVE_SOURCE_GROUP)
+#define MCAST_LEAVE_SOURCE_GROUP 0
+#endif
+
 int UDPSocketPosix::LeaveSourceGroup(const IPAddress& group_address,
                                      const IPAddress& source_address) const {
   DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
