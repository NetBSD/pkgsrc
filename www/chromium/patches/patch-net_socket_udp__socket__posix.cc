$NetBSD: patch-net_socket_udp__socket__posix.cc,v 1.25 2026/09/02 13:13:33 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/socket/udp_socket_posix.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ net/socket/udp_socket_posix.cc
@@ -80,6 +80,14 @@
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
@@ -87,11 +95,37 @@ namespace {
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
@@ -145,7 +179,7 @@ uint32_t GetInterfaceForDestination(cons
 }
 #endif  // BUILDFLAG(IS_MAC)
 
-#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_IOS) && !BUILDFLAG(IS_FUCHSIA)
+#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_IOS) && !BUILDFLAG(IS_FUCHSIA) && !BUILDFLAG(IS_BSD)
 // Helper for IPv4 SSM. Sets sin_len on macOS, no-op on Linux.
 group_source_req CreateIPv4SourceGroupRequest(const IPAddress& group_address,
                                               const IPAddress& source_address,
@@ -277,7 +311,7 @@ int UDPSocketPosix::AdoptOpenedSocket(Ad
   return ConfigureOpenedSocket();
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 namespace {
 
 SetSocketOptionGroResult GetSetSocketOptionGroResult(int setsockopt_rv,
@@ -285,8 +319,12 @@ SetSocketOptionGroResult GetSetSocketOpt
   if (setsockopt_rv == 0) {
     return SetSocketOptionGroResult::kSuccess;
   }
+#if !BUILDFLAG(IS_BSD)
   if (saved_errno == ENOPROTOOPT || saved_errno == EOPNOTSUPP ||
       saved_errno == ENOPKG) {
+#else
+  if (saved_errno == ENOPROTOOPT || saved_errno == EOPNOTSUPP) {
+#endif
     return SetSocketOptionGroResult::kUnsupportedKernel;
   }
   return SetSocketOptionGroResult::kOtherError;
@@ -310,7 +348,7 @@ void RecordGroPacketsRead(size_t packet_
 #endif
 
 void UDPSocketPosix::ConfigureGroSocketOption() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
   CHECK_NE(socket_, kInvalidSocket);
   CHECK_EQ(gro_status_, GroStatus::kUnconfigured);
@@ -523,7 +561,7 @@ base::expected<DatagramsMetadata, Error>
   // when reading coalesced superpackets (e.g. UDP GRO).
   CHECK_GE(buf_len, kMinimumReadMultipleBufferSize);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   if (gro_status_ == GroStatus::kUnconfigured) {
     if (base::FeatureList::IsEnabled(features::kEnableUdpGro)) {
       ConfigureGroSocketOption();
@@ -817,12 +855,17 @@ int UDPSocketPosix::SetRecvTos() {
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
@@ -843,7 +886,7 @@ int UDPSocketPosix::SetBroadcast(bool br
   DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
   int value = broadcast ? 1 : 0;
   int rv;
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   // SO_REUSEPORT on OSX permits multiple processes to each receive
   // UDP multicast or broadcast datagrams destined for the bound
   // port.
@@ -1126,7 +1169,7 @@ void UDPSocketPosix::FillResultFromMessa
       base::byte_span_from_ref(tclass_val).copy_from(cmsg_data_as_span);
       result->tos = static_cast<uint8_t>(tclass_val);
     }
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     else if (gro_status_ == GroStatus::kEnabled &&
              cmsg->cmsg_level == SOL_UDP && cmsg->cmsg_type == UDP_GRO &&
              cmsg->cmsg_len >= CMSG_LEN(sizeof(int)) &&
@@ -1159,7 +1202,7 @@ base::expected<DatagramsMetadata, Error>
   if (socket_ == kInvalidSocket) {
     return base::unexpected(ERR_SOCKET_NOT_CONNECTED);
   }
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   if (gro_status_ == GroStatus::kEnabled) {
     return InternalReadMultipleWithGro(buffer, buf_len, maximum_packet_size);
   }
@@ -1170,7 +1213,7 @@ base::expected<DatagramsMetadata, Error>
 #endif
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 base::expected<DatagramsMetadata, Error> UDPSocketPosix::InternalRecvMmsg(
     IOBuffer* buffer,
     size_t num_messages,
@@ -1501,9 +1544,17 @@ int UDPSocketPosix::SetMulticastOptions(
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
@@ -1538,7 +1589,7 @@ int UDPSocketPosix::DoBind(const IPEndPo
 #if BUILDFLAG(IS_CHROMEOS)
   if (last_error == EINVAL)
     return ERR_ADDRESS_IN_USE;
-#elif BUILDFLAG(IS_APPLE)
+#elif BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   if (last_error == EADDRNOTAVAIL)
     return ERR_ADDRESS_IN_USE;
 #endif
@@ -1567,9 +1618,17 @@ int UDPSocketPosix::JoinGroup(const IPAd
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
@@ -1604,9 +1663,17 @@ int UDPSocketPosix::LeaveGroup(const IPA
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
@@ -1638,7 +1705,7 @@ int UDPSocketPosix::LeaveGroup(const IPA
 int UDPSocketPosix::SetSourceGroupMembership(const IPAddress& group_address,
                                              const IPAddress& source_address,
                                              int option) const {
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return ERR_NOT_IMPLEMENTED;
 #else
   uint32_t interface_index = multicast_interface_;
@@ -1664,6 +1731,10 @@ int UDPSocketPosix::SetSourceGroupMember
 #endif
 }
 
+#if !defined(MCAST_JOIN_SOURCE_GROUP)
+#define MCAST_JOIN_SOURCE_GROUP 0
+#endif
+
 int UDPSocketPosix::JoinSourceGroup(const IPAddress& group_address,
                                     const IPAddress& source_address) const {
   DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
@@ -1680,6 +1751,10 @@ int UDPSocketPosix::JoinSourceGroup(cons
                                   MCAST_JOIN_SOURCE_GROUP);
 }
 
+#if !defined(MCAST_LEAVE_SOURCE_GROUP)
+#define MCAST_LEAVE_SOURCE_GROUP 0
+#endif
+
 int UDPSocketPosix::LeaveSourceGroup(const IPAddress& group_address,
                                      const IPAddress& source_address) const {
   DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
