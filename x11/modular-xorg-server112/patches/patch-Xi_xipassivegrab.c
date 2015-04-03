$NetBSD: patch-Xi_xipassivegrab.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- Xi/xipassivegrab.c.orig	2012-05-17 17:09:01.000000000 +0000
+++ Xi/xipassivegrab.c
@@ -53,6 +53,7 @@ SProcXIPassiveGrabDevice(ClientPtr clien
     xXIModifierInfo *mods;
 
     REQUEST(xXIPassiveGrabDeviceReq);
+    REQUEST_AT_LEAST_SIZE(xXIPassiveGrabDeviceReq);
 
     swaps(&stuff->length);
     swaps(&stuff->deviceid);
@@ -63,6 +64,8 @@ SProcXIPassiveGrabDevice(ClientPtr clien
     swaps(&stuff->mask_len);
     swaps(&stuff->num_modifiers);
 
+    REQUEST_FIXED_SIZE(xXIPassiveGrabDeviceReq,
+        ((uint32_t) stuff->mask_len + stuff->num_modifiers) *4);
     mods = (xXIModifierInfo *) &stuff[1];
 
     for (i = 0; i < stuff->num_modifiers; i++, mods++) {
@@ -88,7 +91,8 @@ ProcXIPassiveGrabDevice(ClientPtr client
     int mask_len;
 
     REQUEST(xXIPassiveGrabDeviceReq);
-    REQUEST_AT_LEAST_SIZE(xXIPassiveGrabDeviceReq);
+    REQUEST_FIXED_SIZE(xXIPassiveGrabDeviceReq,
+        ((uint32_t) stuff->mask_len + stuff->num_modifiers) * 4);
 
     if (stuff->deviceid == XIAllDevices)
         dev = inputInfo.all_devices;
@@ -250,6 +254,7 @@ SProcXIPassiveUngrabDevice(ClientPtr cli
     uint32_t *modifiers;
 
     REQUEST(xXIPassiveUngrabDeviceReq);
+    REQUEST_AT_LEAST_SIZE(xXIPassiveUngrabDeviceReq);
 
     swaps(&stuff->length);
     swapl(&stuff->grab_window);
@@ -257,6 +262,8 @@ SProcXIPassiveUngrabDevice(ClientPtr cli
     swapl(&stuff->detail);
     swaps(&stuff->num_modifiers);
 
+    REQUEST_FIXED_SIZE(xXIPassiveUngrabDeviceReq,
+                       ((uint32_t) stuff->num_modifiers) << 2);
     modifiers = (uint32_t *) &stuff[1];
 
     for (i = 0; i < stuff->num_modifiers; i++, modifiers++)
@@ -275,7 +282,8 @@ ProcXIPassiveUngrabDevice(ClientPtr clie
     int i, rc;
 
     REQUEST(xXIPassiveUngrabDeviceReq);
-    REQUEST_AT_LEAST_SIZE(xXIPassiveUngrabDeviceReq);
+    REQUEST_FIXED_SIZE(xXIPassiveUngrabDeviceReq,
+                       ((uint32_t) stuff->num_modifiers) << 2);
 
     if (stuff->deviceid == XIAllDevices)
         dev = inputInfo.all_devices;
