$NetBSD: patch-dix_swapreq.c,v 1.1 2017/07/28 21:10:00 wiz Exp $

CVE-2017-10971 and CVE-2017-10972: apply fixes to the event loop from

   https://cgit.freedesktop.org/xorg/xserver/commit/?id=ba336b24052122b136486961c82deac76bbde455
   https://cgit.freedesktop.org/xorg/xserver/commit/?id=8caed4df36b1f802b4992edcfd282cbeeec35d9d
   https://cgit.freedesktop.org/xorg/xserver/commit/?id=215f894965df5fb0bb45b107d84524e700d2073c
   https://cgit.freedesktop.org/xorg/xserver/commit/?id=05442de962d3dc624f79fc1a00eca3ffc5489ced

--- dix/swapreq.c.orig	2017-03-15 18:05:25.000000000 +0000
+++ dix/swapreq.c
@@ -292,6 +292,13 @@ SProcSendEvent(ClientPtr client)
     swapl(&stuff->destination);
     swapl(&stuff->eventMask);
 
+    /* Generic events can have variable size, but SendEvent request holds
+       exactly 32B of event data. */
+    if (stuff->event.u.u.type == GenericEvent) {
+        client->errorValue = stuff->event.u.u.type;
+        return BadValue;
+    }
+
     /* Swap event */
     proc = EventSwapVector[stuff->event.u.u.type & 0177];
     if (!proc || proc == NotImplemented)        /* no swapping proc; invalid event type? */
