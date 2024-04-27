$NetBSD: patch-src_network_kernel_qnetworkinterface__unix.cpp,v 1.1 2024/04/27 11:49:40 adam Exp $

On NetBSD, ifr_ifindex is aliased to ifr_index, so avoid redundant definition.

--- src/network/kernel/qnetworkinterface_unix.cpp.orig	2024-04-26 15:14:45.333104123 +0000
+++ src/network/kernel/qnetworkinterface_unix.cpp
@@ -60,11 +60,13 @@ static auto &ifreq_index(Req &req, std::
     return req.ifr_index;
 }
 
+#if !defined(__NetBSD__)
 template <typename Req> [[maybe_unused]]
 static auto &ifreq_index(Req &req, std::enable_if_t<sizeof(std::declval<Req>().ifr_ifindex) != 0, int> = 0)
 {
     return req.ifr_ifindex;
 }
+#endif
 
 uint QNetworkInterfaceManager::interfaceIndexFromName(const QString &name)
 {
