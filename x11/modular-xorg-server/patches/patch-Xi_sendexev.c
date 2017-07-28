$NetBSD: patch-Xi_sendexev.c,v 1.3 2017/07/28 21:10:00 wiz Exp $

CVE-2017-10971 and CVE-2017-10972: apply fixes to the event loop from

   https://cgit.freedesktop.org/xorg/xserver/commit/?id=ba336b24052122b136486961c82deac76bbde455
   https://cgit.freedesktop.org/xorg/xserver/commit/?id=8caed4df36b1f802b4992edcfd282cbeeec35d9d
   https://cgit.freedesktop.org/xorg/xserver/commit/?id=215f894965df5fb0bb45b107d84524e700d2073c
   https://cgit.freedesktop.org/xorg/xserver/commit/?id=05442de962d3dc624f79fc1a00eca3ffc5489ced

--- Xi/sendexev.c.orig	2017-03-15 18:05:25.000000000 +0000
+++ Xi/sendexev.c
@@ -78,7 +78,7 @@ SProcXSendExtensionEvent(ClientPtr clien
 {
     CARD32 *p;
     int i;
-    xEvent eventT;
+    xEvent eventT = { .u.u.type = 0 };
     xEvent *eventP;
     EventSwapPtr proc;
 
@@ -95,9 +95,17 @@ SProcXSendExtensionEvent(ClientPtr clien
 
     eventP = (xEvent *) &stuff[1];
     for (i = 0; i < stuff->num_events; i++, eventP++) {
+        if (eventP->u.u.type == GenericEvent) {
+            client->errorValue = eventP->u.u.type;
+            return BadValue;
+        }
+
         proc = EventSwapVector[eventP->u.u.type & 0177];
-        if (proc == NotImplemented)     /* no swapping proc; invalid event type? */
+        /* no swapping proc; invalid event type? */
+        if (proc == NotImplemented) {
+            client->errorValue = eventP->u.u.type;
             return BadValue;
+        }
         (*proc) (eventP, &eventT);
         *eventP = eventT;
     }
@@ -117,7 +125,7 @@ SProcXSendExtensionEvent(ClientPtr clien
 int
 ProcXSendExtensionEvent(ClientPtr client)
 {
-    int ret;
+    int ret, i;
     DeviceIntPtr dev;
     xEvent *first;
     XEventClass *list;
@@ -141,10 +149,12 @@ ProcXSendExtensionEvent(ClientPtr client
     /* The client's event type must be one defined by an extension. */
 
     first = ((xEvent *) &stuff[1]);
-    if (!((EXTENSION_EVENT_BASE <= first->u.u.type) &&
-          (first->u.u.type < lastEvent))) {
-        client->errorValue = first->u.u.type;
-        return BadValue;
+    for (i = 0; i < stuff->num_events; i++) {
+        if (!((EXTENSION_EVENT_BASE <= first[i].u.u.type) &&
+            (first[i].u.u.type < lastEvent))) {
+            client->errorValue = first[i].u.u.type;
+            return BadValue;
+        }
     }
 
     list = (XEventClass *) (first + stuff->num_events);
