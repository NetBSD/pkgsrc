$NetBSD: patch-Xi_sendexev.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- Xi/sendexev.c.orig	2012-05-17 17:09:01.000000000 +0000
+++ Xi/sendexev.c
@@ -135,6 +135,9 @@ ProcXSendExtensionEvent(ClientPtr client
     if (ret != Success)
         return ret;
 
+    if (stuff->num_events == 0)
+        return ret;
+
     /* The client's event type must be one defined by an extension. */
 
     first = ((xEvent *) &stuff[1]);
