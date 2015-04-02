$NetBSD: patch-src_savage__dri.c,v 1.1 2015/04/02 22:16:48 tnn Exp $

From d28cd83c7b0b4a943efbe5ddf257c8ee2646ea73 Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Tue, 29 Jul 2014 09:15:26 -0400
Subject: dri: Stop (uselessly) initializing the ValidateTree hooks

Signed-off-by: Adam Jackson <ajax@redhat.com>

diff --git a/src/savage_dri.c b/src/savage_dri.c
index bdb78e4..0842821 100644
--- src/savage_dri.c
+++ src/savage_dri.c
@@ -875,9 +875,6 @@ Bool SAVAGEDRIScreenInit( ScreenPtr pScreen )
    psav->coreWakeupHandler = pDRIInfo->wrap.WakeupHandler;
    pDRIInfo->wrap.WakeupHandler = SAVAGEWakeupHandler;
 
-   pDRIInfo->wrap.ValidateTree = NULL;
-   pDRIInfo->wrap.PostValidateTree = NULL;
-
    pDRIInfo->createDummyCtx = TRUE;
    pDRIInfo->createDummyCtxPriv = FALSE;
 
