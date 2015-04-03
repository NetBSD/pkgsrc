$NetBSD: patch-randr_rrsdispatch.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- randr/rrsdispatch.c.orig	2012-05-17 17:09:05.000000000 +0000
+++ randr/rrsdispatch.c
@@ -27,6 +27,7 @@ SProcRRQueryVersion(ClientPtr client)
 {
     REQUEST(xRRQueryVersionReq);
 
+    REQUEST_SIZE_MATCH(xRRQueryVersionReq);
     swaps(&stuff->length);
     swapl(&stuff->majorVersion);
     swapl(&stuff->minorVersion);
@@ -38,6 +39,7 @@ SProcRRGetScreenInfo(ClientPtr client)
 {
     REQUEST(xRRGetScreenInfoReq);
 
+    REQUEST_SIZE_MATCH(xRRGetScreenInfoReq);
     swaps(&stuff->length);
     swapl(&stuff->window);
     return (*ProcRandrVector[stuff->randrReqType]) (client);
@@ -69,6 +71,7 @@ SProcRRSelectInput(ClientPtr client)
 {
     REQUEST(xRRSelectInputReq);
 
+    REQUEST_SIZE_MATCH(xRRSelectInputReq);
     swaps(&stuff->length);
     swapl(&stuff->window);
     swaps(&stuff->enable);
@@ -152,6 +155,7 @@ SProcRRConfigureOutputProperty(ClientPtr
 {
     REQUEST(xRRConfigureOutputPropertyReq);
 
+    REQUEST_AT_LEAST_SIZE(xRRConfigureOutputPropertyReq);
     swaps(&stuff->length);
     swapl(&stuff->output);
     swapl(&stuff->property);
