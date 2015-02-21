$NetBSD: patch-src_radeon__dri2.c,v 1.1 2015/02/21 11:45:35 tnn Exp $

https://bugs.freedesktop.org/show_bug.cgi?id=47160

--- src/radeon_dri2.c.orig	2014-05-02 21:39:40.000000000 +0000
+++ src/radeon_dri2.c
@@ -583,7 +583,7 @@ static void
 radeon_dri2_client_state_changed(CallbackListPtr *ClientStateCallback, pointer data, pointer calldata)
 {
     DRI2ClientEventsPtr pClientEventsPriv;
-    DRI2FrameEventPtr ref;
+    DRI2FrameEventPtr ref = NULL;
     NewClientInfoRec *clientinfo = calldata;
     ClientPtr pClient = clientinfo->client;
     pClientEventsPriv = GetDRI2ClientEvents(pClient);
