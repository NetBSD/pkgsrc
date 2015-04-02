$NetBSD: patch-src_nv__driver.c,v 1.1 2015/04/02 22:16:47 tnn Exp $

From fc78fe98222b0204b8a2872a529763d6fe5048da Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Tue, 25 Sep 2012 08:54:49 -0400
Subject: Remove mibstore.h

Signed-off-by: Adam Jackson <ajax@redhat.com>

diff --git a/src/nv_driver.c b/src/nv_driver.c
index 6dad6e5..8f35334 100644
--- src/nv_driver.c.orig	2012-07-17 06:47:02.000000000 +0000
+++ src/nv_driver.c
@@ -2550,7 +2550,6 @@ NVScreenInit(SCREEN_INIT_ARGS_DECL)
     if (!pNv->NoAccel)
 	NVAccelInit(pScreen);
     
-    miInitializeBackingStore(pScreen);
     xf86SetBackingStore(pScreen);
     xf86SetSilkenMouse(pScreen);
 
