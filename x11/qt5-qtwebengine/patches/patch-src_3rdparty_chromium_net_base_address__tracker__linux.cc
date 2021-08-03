$NetBSD: patch-src_3rdparty_chromium_net_base_address__tracker__linux.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/net/base/address_tracker_linux.cc.orig	2020-07-08 21:40:46.000000000 +0000
+++ src/3rdparty/chromium/net/base/address_tracker_linux.cc
@@ -5,7 +5,9 @@
 #include "net/base/address_tracker_linux.h"
 
 #include <errno.h>
+#if !defined(OS_BSD)
 #include <linux/if.h>
+#endif
 #include <stdint.h>
 #include <sys/ioctl.h>
 #include <utility>
@@ -177,6 +179,7 @@ AddressTrackerLinux::AddressTrackerLinux
 AddressTrackerLinux::~AddressTrackerLinux() = default;
 
 void AddressTrackerLinux::Init() {
+#if !defined(OS_BSD)
   netlink_fd_.reset(socket(AF_NETLINK, SOCK_RAW, NETLINK_ROUTE));
   if (!netlink_fd_.is_valid()) {
     PLOG(ERROR) << "Could not create NETLINK socket";
@@ -272,6 +275,7 @@ void AddressTrackerLinux::AbortAndForceO
   connection_type_initialized_cv_.Broadcast();
 }
 
+#if !defined(OS_BSD)
 AddressTrackerLinux::AddressMap AddressTrackerLinux::GetAddressMap() const {
   AddressTrackerAutoLock lock(*this, address_map_lock_);
   return address_map_;
@@ -290,6 +294,7 @@ bool AddressTrackerLinux::IsInterfaceIgn
   const char* interface_name = get_interface_name_(interface_index, buf);
   return ignored_interfaces_.find(interface_name) != ignored_interfaces_.end();
 }
+#endif
 
 NetworkChangeNotifier::ConnectionType
 AddressTrackerLinux::GetCurrentConnectionType() {
@@ -348,6 +353,7 @@ void AddressTrackerLinux::HandleMessage(
                                         bool* address_changed,
                                         bool* link_changed,
                                         bool* tunnel_changed) {
+#if !defined(OS_BSD)
   DCHECK(buffer);
   // Note that NLMSG_NEXT decrements |length| to reflect the number of bytes
   // remaining in |buffer|.
@@ -460,6 +466,10 @@ void AddressTrackerLinux::HandleMessage(
         break;
     }
   }
+#else
+  NOTIMPLEMENTED();
+  AbortAndFOrceOnline();
+#endif
 }
 
 void AddressTrackerLinux::OnFileCanReadWithoutBlocking() {
@@ -487,6 +497,7 @@ bool AddressTrackerLinux::IsTunnelInterf
 }
 
 void AddressTrackerLinux::UpdateCurrentConnectionType() {
+#if !defined(OS_BSD)
   AddressTrackerLinux::AddressMap address_map = GetAddressMap();
   std::unordered_set<int> online_links = GetOnlineLinks();
 
@@ -512,6 +523,9 @@ void AddressTrackerLinux::UpdateCurrentC
 
   AddressTrackerAutoLock lock(*this, connection_type_lock_);
   current_connection_type_ = type;
+#else
+  NOTIMPLEMENTED();
+#endif
 }
 
 int AddressTrackerLinux::GetThreadsWaitingForConnectionTypeInitForTesting() {
