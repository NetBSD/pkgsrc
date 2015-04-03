$NetBSD: patch-Xi_xisetdevfocus.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- Xi/xisetdevfocus.c.orig	2012-05-17 17:09:01.000000000 +0000
+++ Xi/xisetdevfocus.c
@@ -44,6 +44,8 @@ int
 SProcXISetFocus(ClientPtr client)
 {
     REQUEST(xXISetFocusReq);
+    REQUEST_AT_LEAST_SIZE(xXISetFocusReq);
+
     swaps(&stuff->length);
     swaps(&stuff->deviceid);
     swapl(&stuff->focus);
@@ -56,6 +58,8 @@ int
 SProcXIGetFocus(ClientPtr client)
 {
     REQUEST(xXIGetFocusReq);
+    REQUEST_AT_LEAST_SIZE(xXIGetFocusReq);
+
     swaps(&stuff->length);
     swaps(&stuff->deviceid);
 
