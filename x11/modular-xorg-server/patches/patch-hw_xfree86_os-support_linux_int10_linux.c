$NetBSD: patch-hw_xfree86_os-support_linux_int10_linux.c,v 1.1 2015/04/25 11:47:03 tnn Exp $

From 0a78b599b34cc8b5fe6fe82f90e90234e8ab7a56 Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?J=C3=BCrg=20Billeter?= <j@bitron.ch>
Date: Sat, 7 Feb 2015 18:13:21 +0100
Subject: int10: Fix error check for pci_device_map_legacy

pci_device_map_legacy returns 0 on success.

Signed-off-by: Jürg Billeter <j@bitron.ch>
Reviewed-by: Adam Jackson <ajax@redhat.com>
Signed-off-by: Peter Hutterer <peter.hutterer@who-t.net>

--- hw/xfree86/os-support/linux/int10/linux.c.orig	2014-09-18 22:53:19.000000000 +0000
+++ hw/xfree86/os-support/linux/int10/linux.c
@@ -75,7 +75,7 @@ readLegacy(struct pci_device *dev, unsig
 {
     void *map;
 
-    if (!pci_device_map_legacy(dev, base, len, 0, &map))
+    if (pci_device_map_legacy(dev, base, len, 0, &map))
         return FALSE;
 
     memcpy(buf, map, len);
