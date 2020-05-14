$NetBSD: patch-mgmt_utils_MgmtUtils.cc,v 1.1 2020/05/14 18:59:48 joerg Exp $

--- mgmt/utils/MgmtUtils.cc.orig	2020-05-13 23:52:41.074491810 +0000
+++ mgmt/utils/MgmtUtils.cc
@@ -373,7 +373,7 @@ mgmt_getAddrForIntr(char *intrName, sock
 
   found = false;
   // Loop through the list of interfaces
-  ifend = (struct ifreq *)(ifc.ifc_buf + ifc.ifc_len);
+  ifend = (struct ifreq *)((char *)ifc.ifc_buf + ifc.ifc_len);
   for (ifr = ifc.ifc_req; ifr < ifend;) {
     if (ifr->ifr_addr.sa_family == AF_INET && strcmp(ifr->ifr_name, intrName) == 0) {
       // Get the address of the interface
