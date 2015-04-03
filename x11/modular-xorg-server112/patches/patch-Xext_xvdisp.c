$NetBSD: patch-Xext_xvdisp.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- Xext/xvdisp.c.orig	2012-05-17 17:09:01.000000000 +0000
+++ Xext/xvdisp.c
@@ -1202,6 +1202,7 @@ static int
 SProcXvQueryExtension(ClientPtr client)
 {
     REQUEST(xvQueryExtensionReq);
+    REQUEST_SIZE_MATCH(xvQueryExtensionReq);
     swaps(&stuff->length);
     return XvProcVector[xv_QueryExtension] (client);
 }
@@ -1210,6 +1211,7 @@ static int
 SProcXvQueryAdaptors(ClientPtr client)
 {
     REQUEST(xvQueryAdaptorsReq);
+    REQUEST_SIZE_MATCH(xvQueryAdaptorsReq);
     swaps(&stuff->length);
     swapl(&stuff->window);
     return XvProcVector[xv_QueryAdaptors] (client);
@@ -1219,6 +1221,7 @@ static int
 SProcXvQueryEncodings(ClientPtr client)
 {
     REQUEST(xvQueryEncodingsReq);
+    REQUEST_SIZE_MATCH(xvQueryEncodingsReq);
     swaps(&stuff->length);
     swapl(&stuff->port);
     return XvProcVector[xv_QueryEncodings] (client);
@@ -1228,6 +1231,7 @@ static int
 SProcXvGrabPort(ClientPtr client)
 {
     REQUEST(xvGrabPortReq);
+    REQUEST_SIZE_MATCH(xvGrabPortReq);
     swaps(&stuff->length);
     swapl(&stuff->port);
     swapl(&stuff->time);
@@ -1238,6 +1242,7 @@ static int
 SProcXvUngrabPort(ClientPtr client)
 {
     REQUEST(xvUngrabPortReq);
+    REQUEST_SIZE_MATCH(xvUngrabPortReq);
     swaps(&stuff->length);
     swapl(&stuff->port);
     swapl(&stuff->time);
@@ -1248,6 +1253,7 @@ static int
 SProcXvPutVideo(ClientPtr client)
 {
     REQUEST(xvPutVideoReq);
+    REQUEST_SIZE_MATCH(xvPutVideoReq);
     swaps(&stuff->length);
     swapl(&stuff->port);
     swapl(&stuff->drawable);
@@ -1267,6 +1273,7 @@ static int
 SProcXvPutStill(ClientPtr client)
 {
     REQUEST(xvPutStillReq);
+    REQUEST_SIZE_MATCH(xvPutStillReq);
     swaps(&stuff->length);
     swapl(&stuff->port);
     swapl(&stuff->drawable);
@@ -1286,6 +1293,7 @@ static int
 SProcXvGetVideo(ClientPtr client)
 {
     REQUEST(xvGetVideoReq);
+    REQUEST_SIZE_MATCH(xvGetVideoReq);
     swaps(&stuff->length);
     swapl(&stuff->port);
     swapl(&stuff->drawable);
@@ -1305,6 +1313,7 @@ static int
 SProcXvGetStill(ClientPtr client)
 {
     REQUEST(xvGetStillReq);
+    REQUEST_SIZE_MATCH(xvGetStillReq);
     swaps(&stuff->length);
     swapl(&stuff->port);
     swapl(&stuff->drawable);
@@ -1324,6 +1333,7 @@ static int
 SProcXvPutImage(ClientPtr client)
 {
     REQUEST(xvPutImageReq);
+    REQUEST_AT_LEAST_SIZE(xvPutImageReq);
     swaps(&stuff->length);
     swapl(&stuff->port);
     swapl(&stuff->drawable);
@@ -1347,6 +1357,7 @@ static int
 SProcXvShmPutImage(ClientPtr client)
 {
     REQUEST(xvShmPutImageReq);
+    REQUEST_SIZE_MATCH(xvShmPutImageReq);
     swaps(&stuff->length);
     swapl(&stuff->port);
     swapl(&stuff->drawable);
@@ -1374,6 +1385,7 @@ static int
 SProcXvSelectVideoNotify(ClientPtr client)
 {
     REQUEST(xvSelectVideoNotifyReq);
+    REQUEST_SIZE_MATCH(xvSelectVideoNotifyReq);
     swaps(&stuff->length);
     swapl(&stuff->drawable);
     return XvProcVector[xv_SelectVideoNotify] (client);
@@ -1383,6 +1395,7 @@ static int
 SProcXvSelectPortNotify(ClientPtr client)
 {
     REQUEST(xvSelectPortNotifyReq);
+    REQUEST_SIZE_MATCH(xvSelectPortNotifyReq);
     swaps(&stuff->length);
     swapl(&stuff->port);
     return XvProcVector[xv_SelectPortNotify] (client);
@@ -1392,6 +1405,7 @@ static int
 SProcXvStopVideo(ClientPtr client)
 {
     REQUEST(xvStopVideoReq);
+    REQUEST_SIZE_MATCH(xvStopVideoReq);
     swaps(&stuff->length);
     swapl(&stuff->port);
     swapl(&stuff->drawable);
@@ -1402,6 +1416,7 @@ static int
 SProcXvSetPortAttribute(ClientPtr client)
 {
     REQUEST(xvSetPortAttributeReq);
+    REQUEST_SIZE_MATCH(xvSetPortAttributeReq);
     swaps(&stuff->length);
     swapl(&stuff->port);
     swapl(&stuff->attribute);
@@ -1413,6 +1428,7 @@ static int
 SProcXvGetPortAttribute(ClientPtr client)
 {
     REQUEST(xvGetPortAttributeReq);
+    REQUEST_SIZE_MATCH(xvGetPortAttributeReq);
     swaps(&stuff->length);
     swapl(&stuff->port);
     swapl(&stuff->attribute);
@@ -1423,6 +1439,7 @@ static int
 SProcXvQueryBestSize(ClientPtr client)
 {
     REQUEST(xvQueryBestSizeReq);
+    REQUEST_SIZE_MATCH(xvQueryBestSizeReq);
     swaps(&stuff->length);
     swapl(&stuff->port);
     swaps(&stuff->vid_w);
@@ -1436,6 +1453,7 @@ static int
 SProcXvQueryPortAttributes(ClientPtr client)
 {
     REQUEST(xvQueryPortAttributesReq);
+    REQUEST_SIZE_MATCH(xvQueryPortAttributesReq);
     swaps(&stuff->length);
     swapl(&stuff->port);
     return XvProcVector[xv_QueryPortAttributes] (client);
@@ -1445,6 +1463,7 @@ static int
 SProcXvQueryImageAttributes(ClientPtr client)
 {
     REQUEST(xvQueryImageAttributesReq);
+    REQUEST_SIZE_MATCH(xvQueryImageAttributesReq);
     swaps(&stuff->length);
     swapl(&stuff->port);
     swapl(&stuff->id);
@@ -1457,6 +1476,7 @@ static int
 SProcXvListImageFormats(ClientPtr client)
 {
     REQUEST(xvListImageFormatsReq);
+    REQUEST_SIZE_MATCH(xvListImageFormatsReq);
     swaps(&stuff->length);
     swapl(&stuff->port);
     return XvProcVector[xv_ListImageFormats] (client);
