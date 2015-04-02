$NetBSD: patch-src_smi__driver.c,v 1.1 2015/04/02 22:16:48 tnn Exp $

From f19d7e463c30f1364e82e8c9f87b8a8407d53680 Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Wed, 9 Jan 2013 22:59:39 -0500
Subject: Remove miInitializeBackingStore()

Signed-off-by: Adam Jackson <ajax@redhat.com>

--- src/smi_driver.c.orig	2015-04-02 19:47:46.000000000 +0000
+++ src/smi_driver.c
@@ -1750,8 +1750,6 @@ SMI_ScreenInit(SCREEN_INIT_ARGS_DECL)
 		   "Done writing mode.  Register dump:\n");
     SMI_PrintRegs(pScrn);
 
-    miInitializeBackingStore(pScreen);
-
 #ifdef HAVE_XMODES
     xf86DiDGAInit(pScreen, (unsigned long)(pSmi->FBBase + pScrn->fbOffset));
 #endif
