$NetBSD: patch-hw_xfree86_common_xf86pciBus.c,v 1.1 2016/11/04 01:12:51 maya Exp $

NetBSD also has nouveau, try to autoload it

--- hw/xfree86/common/xf86pciBus.c.orig	2016-07-15 16:18:11.000000000 +0000
+++ hw/xfree86/common/xf86pciBus.c
@@ -1189,7 +1189,7 @@ xf86VideoPtrToDriverList(struct pci_devi
     {
         int idx = 0;
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
         driverList[idx++] = "nouveau";
 #endif
         driverList[idx++] = "nv";
