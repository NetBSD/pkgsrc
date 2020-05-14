$NetBSD: patch-mgmt_cluster_VMap.cc,v 1.1 2020/05/14 18:59:48 joerg Exp $

--- mgmt/cluster/VMap.cc.orig	2020-05-13 23:51:51.524476341 +0000
+++ mgmt/cluster/VMap.cc
@@ -143,7 +143,7 @@ VMap::VMap(char *interface, unsigned lon
       ats_free(ifbuf);
     }
 
-    ifend = (struct ifreq *)(ifc.ifc_buf + ifc.ifc_len);
+    ifend = (struct ifreq *)((char *)ifc.ifc_buf + ifc.ifc_len);
     // Loop through the list of interfaces
     for (ifr = ifc.ifc_req; ifr < ifend;) {
       if (ifr->ifr_addr.sa_family == AF_INET && strcmp(ifr->ifr_name, "lo0") != 0 &&
