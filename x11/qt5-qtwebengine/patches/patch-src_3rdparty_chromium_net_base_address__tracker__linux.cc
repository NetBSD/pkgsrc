$NetBSD: patch-src_3rdparty_chromium_net_base_address__tracker__linux.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/net/base/address_tracker_linux.cc.orig	2021-02-19 16:41:59.000000000 +0000
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
@@ -285,6 +287,7 @@ void AddressTrackerLinux::AbortAndForceO
   connection_type_initialized_cv_.Broadcast();
 }
 
+#if !defined(OS_BSD)
 AddressTrackerLinux::AddressMap AddressTrackerLinux::GetAddressMap() const {
   AddressTrackerAutoLock lock(*this, address_map_lock_);
   return address_map_;
@@ -303,6 +306,7 @@ bool AddressTrackerLinux::IsInterfaceIgn
   const char* interface_name = get_interface_name_(interface_index, buf);
   return ignored_interfaces_.find(interface_name) != ignored_interfaces_.end();
 }
+#endif
 
 NetworkChangeNotifier::ConnectionType
 AddressTrackerLinux::GetCurrentConnectionType() {
@@ -361,6 +365,7 @@ void AddressTrackerLinux::HandleMessage(
                                         bool* address_changed,
                                         bool* link_changed,
                                         bool* tunnel_changed) {
+#if !defined(OS_BSD)
   DCHECK(buffer);
   // Note that NLMSG_NEXT decrements |length| to reflect the number of bytes
   // remaining in |buffer|.
@@ -473,6 +478,10 @@ void AddressTrackerLinux::HandleMessage(
         break;
     }
   }
+#else
+  NOTIMPLEMENTED();
+  AbortAndFOrceOnline();
+#endif
 }
 
 void AddressTrackerLinux::OnFileCanReadWithoutBlocking() {
@@ -500,6 +509,7 @@ bool AddressTrackerLinux::IsTunnelInterf
 }
 
 void AddressTrackerLinux::UpdateCurrentConnectionType() {
+#if !defined(OS_BSD)
   AddressTrackerLinux::AddressMap address_map = GetAddressMap();
   std::unordered_set<int> online_links = GetOnlineLinks();
 
@@ -525,6 +535,9 @@ void AddressTrackerLinux::UpdateCurrentC
 
   AddressTrackerAutoLock lock(*this, connection_type_lock_);
   current_connection_type_ = type;
+#else
+  NOTIMPLEMENTED();
+#endif
 }
 
 int AddressTrackerLinux::GetThreadsWaitingForConnectionTypeInitForTesting() {
