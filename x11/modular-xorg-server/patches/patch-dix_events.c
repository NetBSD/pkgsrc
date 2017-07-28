$NetBSD: patch-dix_events.c,v 1.1 2017/07/28 21:10:00 wiz Exp $

CVE-2017-10971 and CVE-2017-10972: apply fixes to the event loop from

   https://cgit.freedesktop.org/xorg/xserver/commit/?id=ba336b24052122b136486961c82deac76bbde455
   https://cgit.freedesktop.org/xorg/xserver/commit/?id=8caed4df36b1f802b4992edcfd282cbeeec35d9d
   https://cgit.freedesktop.org/xorg/xserver/commit/?id=215f894965df5fb0bb45b107d84524e700d2073c
   https://cgit.freedesktop.org/xorg/xserver/commit/?id=05442de962d3dc624f79fc1a00eca3ffc5489ced

--- dix/events.c.orig	2017-03-15 18:05:25.000000000 +0000
+++ dix/events.c
@@ -5366,6 +5366,12 @@ ProcSendEvent(ClientPtr client)
         client->errorValue = stuff->event.u.u.type;
         return BadValue;
     }
+    /* Generic events can have variable size, but SendEvent request holds
+       exactly 32B of event data. */
+    if (stuff->event.u.u.type == GenericEvent) {
+        client->errorValue = stuff->event.u.u.type;
+        return BadValue;
+    }
     if (stuff->event.u.u.type == ClientMessage &&
         stuff->event.u.u.detail != 8 &&
         stuff->event.u.u.detail != 16 && stuff->event.u.u.detail != 32) {
