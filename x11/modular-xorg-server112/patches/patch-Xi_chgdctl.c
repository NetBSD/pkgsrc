$NetBSD: patch-Xi_chgdctl.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- Xi/chgdctl.c.orig	2012-05-17 17:09:01.000000000 +0000
+++ Xi/chgdctl.c
@@ -78,7 +78,7 @@ SProcXChangeDeviceControl(ClientPtr clie
 
     REQUEST(xChangeDeviceControlReq);
     swaps(&stuff->length);
-    REQUEST_AT_LEAST_SIZE(xChangeDeviceControlReq);
+    REQUEST_AT_LEAST_EXTRA_SIZE(xChangeDeviceControlReq, sizeof(xDeviceCtl));
     swaps(&stuff->control);
     ctl = (xDeviceCtl *) &stuff[1];
     swaps(&ctl->control);
@@ -116,7 +116,7 @@ ProcXChangeDeviceControl(ClientPtr clien
     devicePresenceNotify dpn;
 
     REQUEST(xChangeDeviceControlReq);
-    REQUEST_AT_LEAST_SIZE(xChangeDeviceControlReq);
+    REQUEST_AT_LEAST_EXTRA_SIZE(xChangeDeviceControlReq, sizeof(xDeviceCtl));
 
     len = stuff->length - bytes_to_int32(sizeof(xChangeDeviceControlReq));
     ret = dixLookupDevice(&dev, stuff->deviceid, client, DixManageAccess);
@@ -184,6 +184,10 @@ ProcXChangeDeviceControl(ClientPtr clien
         break;
     case DEVICE_ENABLE:
         e = (xDeviceEnableCtl *) &stuff[1];
+        if ((len != bytes_to_int32(sizeof(xDeviceEnableCtl)))) {
+            ret = BadLength;
+            goto out;
+        }
 
         status = ChangeDeviceControl(client, dev, (xDeviceCtl *) e);
 
