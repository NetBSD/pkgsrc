$NetBSD: patch-src_tga__driver.c,v 1.1 2015/04/02 22:16:48 tnn Exp $

From b7022db0559cd1b6cd3eb6b5abf6896a607b478d Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Tue, 25 Sep 2012 08:55:00 -0400
Subject: Remove mibstore.h

Signed-off-by: Adam Jackson <ajax@redhat.com>

diff --git a/src/tga_driver.c b/src/tga_driver.c
index dd4f3e6..90d2660 100644
--- src/tga_driver.c
+++ src/tga_driver.c
@@ -46,8 +46,6 @@
 
 /* software cursor */
 #include "mipointer.h"
-/* backing store */
-#include "mibstore.h"
 
 /*  #include "mibank.h" */
 /* colormap manipulation */
@@ -1451,7 +1449,6 @@ TGAScreenInit(SCREEN_INIT_ARGS_DECL)
     
     fbPictureInit (pScreen, 0, 0);
     
-    miInitializeBackingStore(pScreen);
     xf86SetBackingStore(pScreen);
     xf86SetSilkenMouse(pScreen);
 
