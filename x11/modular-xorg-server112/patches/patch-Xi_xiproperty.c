$NetBSD: patch-Xi_xiproperty.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- Xi/xiproperty.c.orig	2012-08-19 15:45:55.000000000 +0000
+++ Xi/xiproperty.c
@@ -1007,10 +1007,9 @@ int
 SProcXListDeviceProperties(ClientPtr client)
 {
     REQUEST(xListDevicePropertiesReq);
+    REQUEST_SIZE_MATCH(xListDevicePropertiesReq);
 
     swaps(&stuff->length);
-
-    REQUEST_SIZE_MATCH(xListDevicePropertiesReq);
     return (ProcXListDeviceProperties(client));
 }
 
@@ -1031,10 +1030,10 @@ int
 SProcXDeleteDeviceProperty(ClientPtr client)
 {
     REQUEST(xDeleteDevicePropertyReq);
+    REQUEST_SIZE_MATCH(xDeleteDevicePropertyReq);
 
     swaps(&stuff->length);
     swapl(&stuff->property);
-    REQUEST_SIZE_MATCH(xDeleteDevicePropertyReq);
     return (ProcXDeleteDeviceProperty(client));
 }
 
@@ -1042,13 +1041,13 @@ int
 SProcXGetDeviceProperty(ClientPtr client)
 {
     REQUEST(xGetDevicePropertyReq);
+    REQUEST_SIZE_MATCH(xGetDevicePropertyReq);
 
     swaps(&stuff->length);
     swapl(&stuff->property);
     swapl(&stuff->type);
     swapl(&stuff->longOffset);
     swapl(&stuff->longLength);
-    REQUEST_SIZE_MATCH(xGetDevicePropertyReq);
     return (ProcXGetDeviceProperty(client));
 }
 
@@ -1243,11 +1242,10 @@ int
 SProcXIListProperties(ClientPtr client)
 {
     REQUEST(xXIListPropertiesReq);
+    REQUEST_SIZE_MATCH(xXIListPropertiesReq);
 
     swaps(&stuff->length);
     swaps(&stuff->deviceid);
-
-    REQUEST_SIZE_MATCH(xXIListPropertiesReq);
     return (ProcXIListProperties(client));
 }
 
@@ -1269,11 +1267,11 @@ int
 SProcXIDeleteProperty(ClientPtr client)
 {
     REQUEST(xXIDeletePropertyReq);
+    REQUEST_SIZE_MATCH(xXIDeletePropertyReq);
 
     swaps(&stuff->length);
     swaps(&stuff->deviceid);
     swapl(&stuff->property);
-    REQUEST_SIZE_MATCH(xXIDeletePropertyReq);
     return (ProcXIDeleteProperty(client));
 }
 
@@ -1281,6 +1279,7 @@ int
 SProcXIGetProperty(ClientPtr client)
 {
     REQUEST(xXIGetPropertyReq);
+    REQUEST_SIZE_MATCH(xXIGetPropertyReq);
 
     swaps(&stuff->length);
     swaps(&stuff->deviceid);
@@ -1288,7 +1287,6 @@ SProcXIGetProperty(ClientPtr client)
     swapl(&stuff->type);
     swapl(&stuff->offset);
     swapl(&stuff->len);
-    REQUEST_SIZE_MATCH(xXIGetPropertyReq);
     return (ProcXIGetProperty(client));
 }
 
