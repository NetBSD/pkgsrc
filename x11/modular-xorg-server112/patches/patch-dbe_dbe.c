$NetBSD: patch-dbe_dbe.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- dbe/dbe.c.orig	2012-05-17 17:09:01.000000000 +0000
+++ dbe/dbe.c
@@ -453,18 +453,20 @@ ProcDbeSwapBuffers(ClientPtr client)
     DbeSwapInfoPtr swapInfo;
     xDbeSwapInfo *dbeSwapInfo;
     int error;
-    register int i, j;
-    int nStuff;
+    unsigned int i, j;
+    unsigned int nStuff;
 
     REQUEST_AT_LEAST_SIZE(xDbeSwapBuffersReq);
     nStuff = stuff->n;          /* use local variable for performance. */
 
     if (nStuff == 0) {
+        REQUEST_SIZE_MATCH(xDbeSwapBuffersReq);
         return Success;
     }
 
     if (nStuff > UINT32_MAX / sizeof(DbeSwapInfoRec))
         return BadAlloc;
+    REQUEST_FIXED_SIZE(xDbeSwapBuffersReq, nStuff * sizeof(xDbeSwapInfo));
 
     /* Get to the swap info appended to the end of the request. */
     dbeSwapInfo = (xDbeSwapInfo *) &stuff[1];
@@ -955,13 +957,16 @@ static int
 SProcDbeSwapBuffers(ClientPtr client)
 {
     REQUEST(xDbeSwapBuffersReq);
-    register int i;
+    unsigned int i;
     xDbeSwapInfo *pSwapInfo;
 
     swaps(&stuff->length);
     REQUEST_AT_LEAST_SIZE(xDbeSwapBuffersReq);
 
     swapl(&stuff->n);
+    if (stuff->n > UINT32_MAX / sizeof(DbeSwapInfoRec))
+        return BadAlloc;
+    REQUEST_FIXED_SIZE(xDbeSwapBuffersReq, stuff->n * sizeof(xDbeSwapInfo));
 
     if (stuff->n != 0) {
         pSwapInfo = (xDbeSwapInfo *) stuff + 1;
