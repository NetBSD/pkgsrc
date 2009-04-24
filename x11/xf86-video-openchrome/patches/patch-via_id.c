$NetBSD: patch-via_id.c,v 1.1.1.1 2009/04/24 16:52:45 sborrill Exp $

--- src/via_id.c.orig	2009-04-24 11:15:06.000000000 +0100
+++ src/via_id.c	2009-04-24 11:15:06.000000000 +0100
@@ -179,6 +179,7 @@
     {"Gigabyte GA-VM900M",                    VIA_P4M900,  0x1458, 0xD000, VIA_DEVICE_CRT},
     {"MSI VR321",                             VIA_P4M900,  0x1462, 0x3355, VIA_DEVICE_CRT | VIA_DEVICE_LCD},
     {"MSI P4M900M / P4M900M2-F/L",            VIA_P4M900,  0x1462, 0x7255, VIA_DEVICE_CRT},
+    {"Twinhead H12V",                         VIA_P4M900,  0x14FF, 0xA00F, VIA_DEVICE_CRT | VIA_DEVICE_LCD},
     {"Everex NC1501/NC1503",                  VIA_P4M900,  0x1509, 0x1E30, VIA_DEVICE_CRT | VIA_DEVICE_LCD},
     {"Clevo M660SE",                          VIA_P4M900,  0x1558, 0x0664, VIA_DEVICE_CRT | VIA_DEVICE_LCD},
     {"Clevo M660SR",                          VIA_P4M900,  0x1558, 0x0669, VIA_DEVICE_CRT | VIA_DEVICE_LCD},
