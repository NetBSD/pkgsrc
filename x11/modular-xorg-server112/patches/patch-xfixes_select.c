$NetBSD: patch-xfixes_select.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- xfixes/select.c.orig	2012-05-17 17:09:05.000000000 +0000
+++ xfixes/select.c
@@ -204,6 +204,7 @@ SProcXFixesSelectSelectionInput(ClientPt
 {
     REQUEST(xXFixesSelectSelectionInputReq);
 
+    REQUEST_SIZE_MATCH(xXFixesSelectSelectionInputReq);
     swaps(&stuff->length);
     swapl(&stuff->window);
     swapl(&stuff->selection);
