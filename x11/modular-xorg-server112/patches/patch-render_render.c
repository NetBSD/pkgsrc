$NetBSD: patch-render_render.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- render/render.c.orig	2014-12-21 14:51:52.000000000 +0000
+++ render/render.c
@@ -271,10 +271,11 @@ ProcRenderQueryVersion(ClientPtr client)
 
     REQUEST(xRenderQueryVersionReq);
 
+    REQUEST_SIZE_MATCH(xRenderQueryVersionReq);
+
     pRenderClient->major_version = stuff->majorVersion;
     pRenderClient->minor_version = stuff->minorVersion;
 
-    REQUEST_SIZE_MATCH(xRenderQueryVersionReq);
     memset(&rep, 0, sizeof(xRenderQueryVersionReply));
     rep.type = X_Reply;
     rep.length = 0;
@@ -1994,7 +1995,7 @@ static int
 SProcRenderQueryVersion(ClientPtr client)
 {
     REQUEST(xRenderQueryVersionReq);
-
+    REQUEST_SIZE_MATCH(xRenderQueryVersionReq);
     swaps(&stuff->length);
     swapl(&stuff->majorVersion);
     swapl(&stuff->minorVersion);
@@ -2005,6 +2006,7 @@ static int
 SProcRenderQueryPictFormats(ClientPtr client)
 {
     REQUEST(xRenderQueryPictFormatsReq);
+    REQUEST_SIZE_MATCH(xRenderQueryPictFormatsReq);
     swaps(&stuff->length);
     return (*ProcRenderVector[stuff->renderReqType]) (client);
 }
@@ -2013,6 +2015,7 @@ static int
 SProcRenderQueryPictIndexValues(ClientPtr client)
 {
     REQUEST(xRenderQueryPictIndexValuesReq);
+    REQUEST_AT_LEAST_SIZE(xRenderQueryPictIndexValuesReq);
     swaps(&stuff->length);
     swapl(&stuff->format);
     return (*ProcRenderVector[stuff->renderReqType]) (client);
@@ -2028,6 +2031,7 @@ static int
 SProcRenderCreatePicture(ClientPtr client)
 {
     REQUEST(xRenderCreatePictureReq);
+    REQUEST_AT_LEAST_SIZE(xRenderCreatePictureReq);
     swaps(&stuff->length);
     swapl(&stuff->pid);
     swapl(&stuff->drawable);
@@ -2041,6 +2045,7 @@ static int
 SProcRenderChangePicture(ClientPtr client)
 {
     REQUEST(xRenderChangePictureReq);
+    REQUEST_AT_LEAST_SIZE(xRenderChangePictureReq);
     swaps(&stuff->length);
     swapl(&stuff->picture);
     swapl(&stuff->mask);
@@ -2052,6 +2057,7 @@ static int
 SProcRenderSetPictureClipRectangles(ClientPtr client)
 {
     REQUEST(xRenderSetPictureClipRectanglesReq);
+    REQUEST_AT_LEAST_SIZE(xRenderSetPictureClipRectanglesReq);
     swaps(&stuff->length);
     swapl(&stuff->picture);
     swaps(&stuff->xOrigin);
@@ -2064,6 +2070,7 @@ static int
 SProcRenderFreePicture(ClientPtr client)
 {
     REQUEST(xRenderFreePictureReq);
+    REQUEST_SIZE_MATCH(xRenderFreePictureReq);
     swaps(&stuff->length);
     swapl(&stuff->picture);
     return (*ProcRenderVector[stuff->renderReqType]) (client);
@@ -2073,6 +2080,7 @@ static int
 SProcRenderComposite(ClientPtr client)
 {
     REQUEST(xRenderCompositeReq);
+    REQUEST_SIZE_MATCH(xRenderCompositeReq);
     swaps(&stuff->length);
     swapl(&stuff->src);
     swapl(&stuff->mask);
@@ -2092,6 +2100,7 @@ static int
 SProcRenderScale(ClientPtr client)
 {
     REQUEST(xRenderScaleReq);
+    REQUEST_SIZE_MATCH(xRenderScaleReq);
     swaps(&stuff->length);
     swapl(&stuff->src);
     swapl(&stuff->dst);
@@ -2192,6 +2201,7 @@ static int
 SProcRenderCreateGlyphSet(ClientPtr client)
 {
     REQUEST(xRenderCreateGlyphSetReq);
+    REQUEST_SIZE_MATCH(xRenderCreateGlyphSetReq);
     swaps(&stuff->length);
     swapl(&stuff->gsid);
     swapl(&stuff->format);
@@ -2202,6 +2212,7 @@ static int
 SProcRenderReferenceGlyphSet(ClientPtr client)
 {
     REQUEST(xRenderReferenceGlyphSetReq);
+    REQUEST_SIZE_MATCH(xRenderReferenceGlyphSetReq);
     swaps(&stuff->length);
     swapl(&stuff->gsid);
     swapl(&stuff->existing);
@@ -2212,6 +2223,7 @@ static int
 SProcRenderFreeGlyphSet(ClientPtr client)
 {
     REQUEST(xRenderFreeGlyphSetReq);
+    REQUEST_SIZE_MATCH(xRenderFreeGlyphSetReq);
     swaps(&stuff->length);
     swapl(&stuff->glyphset);
     return (*ProcRenderVector[stuff->renderReqType]) (client);
@@ -2226,6 +2238,7 @@ SProcRenderAddGlyphs(ClientPtr client)
     xGlyphInfo *gi;
 
     REQUEST(xRenderAddGlyphsReq);
+    REQUEST_AT_LEAST_SIZE(xRenderAddGlyphsReq);
     swaps(&stuff->length);
     swapl(&stuff->glyphset);
     swapl(&stuff->nglyphs);
@@ -2260,6 +2273,7 @@ static int
 SProcRenderFreeGlyphs(ClientPtr client)
 {
     REQUEST(xRenderFreeGlyphsReq);
+    REQUEST_AT_LEAST_SIZE(xRenderFreeGlyphsReq);
     swaps(&stuff->length);
     swapl(&stuff->glyphset);
     SwapRestL(stuff);
@@ -2277,6 +2291,7 @@ SProcRenderCompositeGlyphs(ClientPtr cli
     int size;
 
     REQUEST(xRenderCompositeGlyphsReq);
+    REQUEST_AT_LEAST_SIZE(xRenderCompositeGlyphsReq);
 
     switch (stuff->renderReqType) {
     default:
